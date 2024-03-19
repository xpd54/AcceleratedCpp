//
//  main.cpp
//  workingWithContainer
//
//  Created by Ravi on 17/3/2024.
//
// Take discription of sentences or call it grammer and generate a sentence.
#include <iostream>
#include <map>
#include "split.h"
#include "counting_words.h"
#include "read_grammer.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::string hello_world = std::string("Hello, World! well where we will go from here.");
    std::vector<std::string> splitVector = split(hello_world);
    for(const std::string &word : splitVector) {
        std::cout << word << "\n";
    }
    
    
    std::map<std::string, int> counted = countingWords();
    
    for(std::map<std::string, int>::const_iterator it = counted.begin(); it != counted.end(); ++it) {
        std::cout << it->first << "\t" << it->second << "\n";
    }
    
    return 0;
}
