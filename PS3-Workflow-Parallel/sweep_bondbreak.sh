#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=16
#SBATCH --time=00:20:00
#SBATCH --output=sweep_bondbreak_output1.txt

# This is the sweep_bondbreak.sh script

module load python # bondbreak needs python
module load gnu-parallel

# Run multiple cases with different random seeds
X=1.2      # initial bond extension
T=2.2      # temperature
DT=0.0003  # timestep
MT=400.0   # max.time to simulate
ODT=1.0    # interval at which write data
NREPS=96   # how many repeats
for ((S=1; S<=NREPS; S++)) ; do
 echo "Repetition $S/$NREPS"
 DFN=out/output-$T-$S.data
 LFN=out/output-$T-$S.log
 time ./bondbreak $X $T $DT $MT $S $DFN $ODT $LFN
done | parallel -j

# Extract the breakage times from the logs
awk '/BREAKAGE DETECTED/{print $8}' out/*.log 
