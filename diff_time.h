//
// Created by 金琪 on 2021/8/4.
//

#pragma once
#include <iostream>
#include <chrono>

using STEADY_CLOCK = std::chrono::steady_clock;
using TIME_POINT = std::chrono::steady_clock::time_point;

void print_diff(const TIME_POINT &t1, const TIME_POINT &t2) {
    std::chrono::duration<double, std::milli> dTimeSpan = std::chrono::duration<double, std::milli>(t2 - t1);
    std::cout << "time span: " << dTimeSpan.count() << "ms\n";
}

