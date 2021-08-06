//
// Created by 金琪 on 2021/8/4.
//
#include "diff_time.h"
#include <iostream>
#include <thread>
#include <future>
#include <functional>

using namespace std;
using T = function<int()>;

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
    promise<T> pr1;
    promise<T> pr2;
    future<T> f1 = pr1.get_future();
    future<T> f2 = pr2.get_future();

    pr1.set_value(calculateA);
    pr2.set_value(calculateB);
    auto calA = f1.get();
    auto calB = f2.get();
    thread th1(calA);
    thread th2(calB);
    th1.join();
    th2.join();
//    int sum = calA() + calB();
    int sum = 0;
    TIME_POINT t2 = STEADY_CLOCK::now();
    cout << "test_promise_time result is: " << sum << " ";
    print_diff(t1, t2);
    promise<int> p;
    future<int> f = p.get_future();
    return 0;
}
