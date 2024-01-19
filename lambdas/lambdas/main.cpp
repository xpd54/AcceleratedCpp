//
//  main.cpp
//  lambdas
//
//  Created by RaviPrakash on 18/1/2024.
//

#include <iostream>
#include <string_view>
#include <algorithm>
#include <array>
#include <functional>

void repeat1(int repetitions, const std::function<void(int)> &fn) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
}

template <typename T>
void repeat2(int repetitions, const T& fn) {
    for (int i{0}; i<repetitions; ++i) {
        fn(i);
    }
}

void repeat3(int repetitions, const auto& fn) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
}


int main(int argc, const char * argv[]) {
    constexpr std::array<std::string_view, 4> array = {"apple", "banana", "walnut", "lemon"};
    auto found{
        std::find_if(array.begin(), array.end(), [](std::string_view str){
            return str.find("nut") != std::string_view::npos;
        })
    };

    if(found == array.end()) {
        std::cout << "No Nuts\n";
    } else {
        std::cout << "Found " << *found << '\n';
    }

    auto isEven = [](int i){
        return i%2;
    };
    std::array<int, 5> even_array = {2,4,5,6,8};
    bool all_are_even = std::all_of(even_array.begin(), even_array.end(), isEven);
    std::cout << all_are_even << "\n";
    
    // A Regular function pointer which only works with empty capture clause
    std::function addNumbers{
        [](double a, double b) {
            return a + b;
        }
    };
    
    std::cout << addNumbers(3,5) << '\n';
    auto addNumbers1 = [](double a, double b){
        return a + b;
    };
    
    std::cout << addNumbers1(45, 34) << '\n';
    
    auto lambdas = [](int i) {
        std::cout << i << '\n';
    };
    
    repeat1(3, lambdas);
    repeat2(3, lambdas);
    repeat3(3, lambdas);
    return 0;
}

