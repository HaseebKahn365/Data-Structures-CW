#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace this_thread;
using namespace chrono;

int main() {
    int counter = 0;
    const int maxCount = 100; // You can adjust this value based on your requirements

    // while (counter <= maxCount) {
    //     std::cout << "Loading... " << counter << "%" << std::flush;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust the delay as needed
    //     std::cout << "\r"; // Move cursor back to the beginning of the line

    //     counter++;
    // }

    std::cout << "Loading complete!" << std::endl;



     bool condition = false;

    // Busy waiting loop
    while (!condition) {
        // Do nothing, just keep checking the condition
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Introduce a short delay to avoid high CPU usage
        condition = true;
    }

    std::cout << "Condition is true, exiting the loop." << std::endl;

    sleep_for(milliseconds(300));

    while(condition);
    cout<<"this is the end of the code";

    return 0;
}
