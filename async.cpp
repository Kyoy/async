//
// Created by 金琪 on 2021/8/4.
//
#include "diff_time.h"
#include <iostream>
#include <thread>
#include <future>

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
    future<int> f1 = async(calculateA);
    future<int> f2 = async(calculateB);
    int sum = f1.get() + f2.get();
    TIME_POINT t2 = STEADY_CLOCK::now();
    cout << "test_async_time result is: " << sum << " ";
    print_diff(t1, t2);
    return 0;
}
