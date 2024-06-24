srun --partition=short -N 1 --ntasks=1 --cpus-per-task=8 --gres=gpu:0 -t 00:05:00 --account=iecsparallelprog --reservation=iecsparallelprog_32 --pty bash
