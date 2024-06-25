#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char* argv[])
{

  //TODO 3 - Done
  int thread_count = 6;

  //TODO 5 - Done 
  //TODO 1 - Done
   int myID = omp_get_thread_num();

  //TODO 2 - Done
   int num_threads = omp_get_num_threads();
#pragma omp parallel num_threads(thread_count) //TODO 4 - Done 
    {

      //TODO 1 - Done
      //int myID = omp_get_thread_num(); 

      //TODO 2 - Done
      //int num_threads = omp_get_num_threads(); 
  
      printf("Hello from thread %d of %d\n", myID, num_threads);
    }

  return 0;
}
