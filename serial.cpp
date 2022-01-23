// This program shows are the basics of using the parallel STL in C++
// credits : https://www.youtube.com/watch?v=xyDUPkq90pQ (reference video)
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

// Helper function for getting the current time for profiling
auto get_time() { return std::chrono::high_resolution_clock::now(); }

int main()
{
    // Size of our vector
    const int N = 1 << 20;

    // Create our vector
    std::vector<int> v(N);

    // Set up our random number generator
    std::mt19937 rng;                                //  Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
    rng.seed(std::random_device()());                //  Seed the random number generator with a random value.
    std::uniform_int_distribution<int> dist(0, 255); //  Uniform distribution of integers in the range [0, 255].

    // Generate our random inputs
    std::generate(begin(v), end(v), [&]()
                  { return dist(rng); }); //  Generate N random numbers and store them in the vector.

    // Reduce the vector in parallel and vectorized
    auto start = get_time();     //  Get the current time before the start of sort.
    std::sort(begin(v), end(v)); //  Sort the vector in series.
    auto finish = get_time();    //  Get the current time after sort is done.

    // Print out the execution time
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(finish - start); //  Get the duration of the sort.
    std::cout << "Elapsed time = " << duration.count() << " ms\n";             //  Print the duration of the sort.

    return 0; //  Return 0 to indicate success.
}
