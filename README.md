<!-- Documentation to compile the following codes -->

# Active Learning OOP

## Parallel and Concurrent programming with C++


----------------------------------------------------------------

The codes consist of the following: 

- sleep_thread.cpp : Demonstrates the use of pthread library to work with posix threads and demonstrates how the threads are independent. 

To compile the code :
```
g++ sleep_thread.cpp -lpthread
```

- serial.cpp : Uses the stl function to sort random arrays and outputs the execution time, but without the c++17 parallel optimizations to stl library.

To compile the code :
```
g++ -o3 serial.cpp
```

- Parallel.cpp : Does the same as serial.cpp but uses the parallel optimizations by including 
```
#include <execution>
and std::execution::par
```

To compile the code :
```
g++ parallel.cpp -O3 -ltbb --std=c++2a
```




