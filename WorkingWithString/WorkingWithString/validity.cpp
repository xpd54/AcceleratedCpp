//
//  validity.cpp
//  WorkingWithString
//
//  Created by RaviPrakash on 14/1/2024.
//

#include <iostream>
#include <string>
void validity() {
    const std::string hello = "Hello";
    // we can use + to concatinate 2 strings or string and string literal
    // but we can't use + to concatinate 2 string literals.
    // following case first + converts string literals to strins. 
    const std::string message = hello + ", world" + "!";
}

void validityScope() {
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
    }
    {
        const std::string s = "another string";
        std::cout << s << std::endl;
    }
}

void vlidityScopeDoubleScope() {
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
        {
            const std::string s = "another string";
            std::cout << s << std::endl;
        }
    }
}

void validityBuffer() {
    std::cout << "what's your name";
    std::string name;
    std::cin >> name;
    std::cout << "hello " + name << std::endl << "And what is your name ";
    std::cin >> name;
    std::cout << "hello " + name << "! nice to meet you" << std::endl;
}
