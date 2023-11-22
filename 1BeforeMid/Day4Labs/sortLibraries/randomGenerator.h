
#include <cstdlib>  // Required for rand() function
#include <ctime>

void InitArray(float arr[], int N) {

    srand(time(0));

    for (int i = 0; i < N; i++) {
        // Generate a random float between 0 and 1000
        float randomFloat = (rand()%1000 ) *(0.9 - rand()%1);

        // Store the random float value in the array
        arr[i] = randomFloat;
    }
}