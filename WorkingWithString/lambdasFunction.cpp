//
//  lambdasFunction.cpp
//  WorkingWithString
//
//  Created by RaviPrakash on 16/1/2024.
//

#include "lambdasFunction.hpp"
#include <array>
#include <string_view>
#include <iostream>

bool containsNut(std::string_view str) {
    return str.find("nut") != std::string_view::npos;
}

void findIfExist() {
    constexpr std::array<std::string_view, 4> arr {"apple","banana", "walnut", "lemon"};
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut)};
    
    if(found == arr.end()) {
        std::cout << "No nuts\n";
    }
    else {
        std::cout << "Found" << *found << '\n';
    }
}

void findWithLambdas() {
    constexpr std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};
    auto found{std::find_if(arr.begin(), arr.end(), [](std::string_view str){
        return str.find("nut") != std::string_view::npos;
    })};
    
    if (found == arr.end()) {
        std::cout << "No nuts\n";
    } else {
        std::cout << "Found " << *found << '\n';
    }
}
