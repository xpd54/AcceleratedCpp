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
    return 0;
}
