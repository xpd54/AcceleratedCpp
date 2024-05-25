//
//  writeAframe.cpp
//  WorkingWithString
//
//  Created by RaviPrakash on 24/5/2024.
//

#include "writeAframe.hpp"
#include <iostream>
#include <string>
void WriteInAFrame() {
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    // build message intened to write
    const std::string greeting = "Hello, " + name + "!";
    const std::string spaces(greeting.size(), ' '); // have to be char can't be string
    const std::string secondLine = "* " + spaces + " *";
    const std::string firstLine(secondLine.size(), '*');
    
    // write it all
    std::cout << firstLine << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << "* " + greeting + " *" << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << firstLine << std::endl;
}
