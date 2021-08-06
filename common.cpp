#include <iostream>
#include <thread>
#include "diff_time.h"

using namespace std;

int calculateA() {
    this_thread::sleep_for(chrono::milliseconds(2));
    return 2;
}

int calculateB() {
    this_thread::sleep_for(chrono::milliseconds(3));
    return 3;
}

int main() {
    TIME_POINT t1 = STEADY_CLOCK::now();
    int c = calculateA() + calculateB();
    TIME_POINT t2 = STEADY_CLOCK::now();
    cout << "test_common_time result is: " << c << " ";
    print_diff(t1, t2);
    return 0;
}
