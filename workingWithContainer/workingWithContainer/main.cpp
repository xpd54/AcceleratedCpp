//
//  main.cpp
//  workingWithContainer
//
//  Created by Ravi on 17/3/2024.
//
// Take discription of sentences or call it grammer and generate a sentence.
#include "container.cpp"
#include <unordered_set>
int main(int argc, const char * argv[]) {
    Container<std::unordered_set<int>> container;
    do {
        container.rollAndShow();
    } while (getc(stdin));
    
//    Container second = Container<std::list<int>>();
//    second.rollAndShow();
    
    
    return 0;
}
