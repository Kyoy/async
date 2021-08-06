//
// Created by 金琪 on 2021/8/4.
//
#include "diff_time.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void calA(int &sum) {
    this_thread::sleep_for(chrono::milliseconds(2));
    lock_guard<mutex> lk(mtx);
    sum += 2;
}

void calB(int &sum) {
    this_thread::sleep_for(chrono::milliseconds(3));
    lock_guard<mutex> lk(mtx);
    sum += 3;
}

int main() {
    int sum = 0;
    TIME_POINT tp1 = STEADY_CLOCK::now();
    thread t1(calA, ref(sum));
    thread t2(calB, ref(sum));
    t1.join();
    t2.join();
    TIME_POINT tp2 = STEADY_CLOCK::now();
    cout << "test_threads_time result is: " << sum << " ";
    print_diff(tp1, tp2);
    return 0;
}