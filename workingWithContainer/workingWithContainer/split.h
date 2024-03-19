//
//  split.h
//  workingWithContainer
//
//  Created by Ravi on 17/3/2024.
//

#ifndef split_h
#define split_h

#include <ctype.h>
#include <vector>
#include <string>
bool space(char c) {
    return isspace(c);
}

bool not_space(char c) {
    return !isspace(c);
}

std::vector<std::string> split(const std::string &str) {
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter i = str.begin();
    
    while (i != str.end()) {
        // ignore leading space
        i = std::find_if(i, str.end(), not_space);
        // find end of next word
        iter j = find_if(i, str.end(), space);
        
        // push the word into ret vector
        if(i != str.end()) {
            ret.push_back(std::string(i, j));
        }
        // move i till j
        i = j;
    }
    return ret;
}

#endif /* split_h */
