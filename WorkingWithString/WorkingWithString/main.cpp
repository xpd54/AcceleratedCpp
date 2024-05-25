//
//  main.cpp
//  WorkingWithString
//
//  Created by RaviPrakash on 14/1/2024.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    std::string holding = "Hello I am holding a huge string";
    for (auto &value : holding) {
        value = value == 'h' ? 'x' : value;
        std::cout << value;
    }
    std::cout << "\n";
    std::cout << holding << "\n";
    return 0;
}
