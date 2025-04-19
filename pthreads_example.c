// example showing simple multi-threaded program using posix thread library
// (pthread) which implements threads in userspace
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// pointer to function that runs as a routine for each pthread
// It simply prints the thread id for now
void *print_thread_info(void *tid) {
  printf("thread id: %d\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  // check if no. of threads to run is provided as an command line argument
  // If not then show error msg and exit the program
  if (argc < 2) {
    fprintf(stderr, "error: no of threads not provided!");
    exit(-1);
  }
  // get no. of threads from command line argument
  int no_of_threads = atoi(argv[1]);
  int status, i;
  pthread_t threads[no_of_threads];
  for (i = 0; i <= no_of_threads; i++) {
    // create a new thread and store it in array and pass print_thread_info as
    // routine and index i as its argument
    status = pthread_create(&threads[i], NULL, print_thread_info, (void *)i);
    // exit with error msg if unable to create a thread
    if (status != 0) {
      fprintf(stderr, "error: unable to create a thread. returned code: %d",
              status);
      exit(-1);
    }
  }
  return 0;
}
