//
//  counting_words.h
//  workingWithContainer
//
//  Created by Ravi on 17/3/2024.
//

#ifndef counting_words_h
#define counting_words_h

#include <map>
std::map<std::string, int> countingWords() {
    std::string str;
    std::map<std::string, int> counters;
    while(std::cin >> str) {
        ++counters[str];
    }
    return counters;
}

#endif /* counting_words_h */
