#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=16
#SBATCH --time=00:20:00
#SBATCH --job-name=parallel-bond

module load gcc
module load gnu-parallel

export OMP_NUM_THREADS=16
./parallel
