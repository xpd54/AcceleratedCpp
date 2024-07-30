//
//  container.cpp
//  workingWithContainer
//
//  Created by Ravi on 30/7/2024.
//
#include<vector>
#include<iostream>
template <typename T>
class Container {
public:
    Container(): bag(T()) {
        bag.insert(rollingDice());
        firstLocation = &(*bag.begin());
    }
    void rollAndShow() {
        bag.insert(rollingDice());
        const int *currentFirstLocation = &(*bag.begin());
        for(auto &i : bag) {
            const int *itemLocation = &i;
            auto itemOffSet = itemLocation - currentFirstLocation;
            auto itemOriginalOffSet = itemLocation - firstLocation;
            std::cout << "Original Offset:- " << itemOriginalOffSet << " " << "From Zero:- " << itemOffSet << " value:- " << i << " size:- " << bag.size() <<"\n";
        }
        
    }
    ~Container() {
        std::cout << "Getting Cleared " << bag.size() << "\n";
    }
private:
    T bag;
    const int *firstLocation;
    int rollingDice() {
        auto roll = [](){ return rand() % 6 + 1;};
        return roll();
    }
};
