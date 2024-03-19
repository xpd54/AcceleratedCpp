//
//  read_grammer.h
//  workingWithContainer
//
//  Created by Ravi on 18/3/2024.
//

#ifndef read_grammer_h
#define read_grammer_h
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "split.h"
typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_Collection;
typedef std::map<std::string, Rule_Collection> Grammer;

Grammer read_grammer(std::istream &in) {
    Grammer ret;
    std::string line;
    while (std::getline(in, line)) {
        // split the input into words
        std::vector<std::string> entry = split(line);
        if(!entry.empty()) {
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}

bool bracketed(const std::string &s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

int nrand(int n) {
    if(n <= 0 || n > RAND_MAX)
        throw std::domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX/n;
    int r;
    do
        r = std::rand() / bucket_size;
    while(r >= n);
    return  r;
}

void gen_aux(const Grammer &g, const std::string &word, std::vector<std::string> &ret) {
    // base case if word is not bracketed that's mean it's not a rule_collection
    // so push it into return vector
    if(!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate the rule which corresponds to word
        Grammer::const_iterator it = g.find(word);
        if(it == g.end()) {
            throw std::logic_error("empty rule");
        }
        
        // fetch the set of possible rules
        const Rule_Collection &c = it->second;
        
        // from which we select on at random
        const Rule &r = c[nrand(c.size())];
        
        // recursively expand the selected rule
        for(Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
            gen_aux(g, *i, ret);
        }
    }
}

std::vector<std::string> gen_sentence(const Grammer &g) {
    std::vector<std::string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

#endif /* read_grammer_h */
