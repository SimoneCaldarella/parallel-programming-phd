# Parallel Programming Phd Course
Repository for the PhD course Parallel Programming


## Day 1 - OpenMP Basics

### Lab 1 - Sum

We used `omp_get_thread_num()` and `omp_get_num_threads()` to retriebe the thread identifier and the total number of threads. We experimented with the first omp `#pragma` by using `#pragma omp parallel num_threads(thread_count)` to generate a variable number of threads (not guaranteed). We finally showed that by moving `omp_get_num_threads()` and `omp_get_thread_num()` outside the parallel region their value is respectively 1 and 0 (i.e., a single thread).


### Lab 2 - Reduction

In the first main we learnt about private and shared variables, defined with omp pragmas, and critical regions. To avoid race conditions, the variable where we store the partial sum is kept private, while the total sum is shared, but accessible only from one thread at a time (critical regions work like mutex).

In the second main we used the reduction construct, which is basically designed to simplify the above code, avoiding to define a parallel for followed by a critical region.


### Lab 3 - Stream

We run a benchmark (stream) to assess the memory bandwidth of the system. Four operations have been used to trace the bandwidth and through the environment variable `OMP_NUM_THREADS` we showed more threads increase the bandwidth.


## Day 2 - CUDA Basics

### Lab 1 - DeviceQuery

We run a tool which showed the full specs of the CUDA device available in the current session


### Lab 2 - Hello

The hello world equivalent for CUDA. We coded our first CUDA kernel and tried to change the number of threads and thread blocks to print the string "Hello World".


### Lab 3 - VectorAdd

We fixed some portions of the code to correctly perform vector addition.
For example we computed the correct indices using `threadIdx.x + blockIdx.x * blockDim.x`, we copied the variable from the host memory (cpu) to the gpu memory using `cudaMemcpy` and we deallocated all the previously allocated variables.


### Lab 4 - Stencil 1D

We implemented two versions of the stencil problem.In the first one, we implemented the solution by accessing each RADIUS*2 + 1 variables for each element of the final vector. As this leads to redundant memory accesses, we implemented a more efficient versions that uses shared memory (which is faster than the global one). However this requires a `__syncthreads` to ensure all threads of the same block ended the task (differently from OpenMP, in CUDA barrier are not implicitly defined).


### Lab 5 - Bandwidth Test 

Using a tool we tested how the bandwidth changed using pinned memory (better) rather than pageable memory (worse).


## Day 3 - CUDA Intermediate

### Lab 6 - VectorAdd UVM

We compute vector addition between floating point numbers by having each thread computing the pairwise sum. We learn to use `cudaMalloc` and `cudaDeviceSynchronize`.

### Lab 7 - MatMul [most difficult lab]

We implemented matrix multiplication from scratch, from the naive way, using nested for loops to a more optimized way. In our initial matrix multiplication code, much like with previous lab, the performance was hindered by too many global memory accesses. To address this, we developed an optimized version which uses two sliding windows, each matching the size of a block. Threads within a block can load matrix sections into shared memory to compute partial dot products, which are then summed to obtain the final matrix multiplication.

### Lab 9 - Reduction

We used a tool and tried 6 types of reduction, from the most naive one with non contiguous threads to the most optimized one. We simply used the parameter `kernel` to set what it was the algorithm choice and then we measured the Effective Bandwidth.

### Lab 10 - MultiGPUs

I tried to implement this one for a while, but didn't fully got how to do it. I also tried to ask chatgpt to explain it, but failed. The current solution is not working.







