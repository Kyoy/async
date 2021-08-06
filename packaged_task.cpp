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
    packaged_task<int()> task1(calculateA);
    packaged_task<int()> task2(calculateB);
    future<int> f1 = task1.get_future();
    future<int> f2 = task2.get_future();
    thread th1(move(task1));
    thread th2(move(task2));
    th1.join();
    th2.join();
    int sum = f1.get() + f2.get();
    TIME_POINT t2 = STEADY_CLOCK::now();
    cout << "test_packaged_task_time result is: " << sum << " ";
    print_diff(t1, t2);
    return 0;
}