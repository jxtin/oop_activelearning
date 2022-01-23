// Program to use pthread and sleep functions to demonstrate threading

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

// Function to be executed by thread created, passed as argument to pthread_create and requires integer argument
void *PrintHello(void *threadid)
{
    long tid;                                                                // thread id
    tid = (long)threadid;                                                    // cast void* to long
    cout << "Hello World! It's me, thread #" << tid << endl;                 // print thread id
    cout << "Thread #" << tid << " is going to sleep for 3 seconds" << endl; // print thread id
    sleep(3);                                                                // sleep for 3 seconds
    cout << "Thread #" << tid << " will exit" << endl;                       // announce thread exit
    pthread_exit(NULL);                                                      // exit thread
}

int main()
{
    pthread_t threads[NUM_THREADS]; // Array of threads
    int rc;                         // Return code
    int i;                          // Loop counter

    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "In main: creating thread #" << i << endl;                         // print thread id of thread being created in main
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);             // create thread
        cout << "main() : done creating thread, " << i << endl;                    // print thread id of thread created in main
        cout << "main thread will sleep for 1 second before next thread." << endl; // announce main thread sleep
        sleep(1);                                                                  // sleep for 1 second
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl; // print error if thread creation fails
            exit(-1);                                               // exit program
        }
    }
    cout << "Main thread will sleep for 7 seconds" << endl; // announce main thread sleep
    sleep(7);                                               // sleep for 7 seconds
    cout << "Main thread will exit" << endl;                // announce main thread exit
    pthread_exit(NULL);                                     // exit main thread
}
