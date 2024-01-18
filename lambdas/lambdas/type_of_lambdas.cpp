//
//  type_of_lambdas.cpp
//  lambdas
//
//  Created by RaviPrakash on 19/1/2024.
//
#include <functional>
#include <iostream>
#include "type_of_lambdas.hpp"

// Case 1: use a 'std::function' parameter
void repeat1(int repetitions, const std::function<void(int)> &fn) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
}

// Case 2: use a function template with a type template parameter
template <typename T>
void repeat2(int repetitions, const T& fn) {
    for (int i{0}; i<repetitions; ++i) {
        fn(i);
    }
}

// Case 3: use the abbreviated function template syntax (c++20)
void repeat3(int repetitions, const auto& fn) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
}

