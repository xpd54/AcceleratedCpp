//
//  main.cpp
//  WorkingWithScope
//
//  Created by Ravi on 15/3/2024.
//

#include <iostream>
int reused = 42;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Global :- " << reused << "\n";
    int reused = 0;
    std::cout << "Local :- " << reused << "\n";
    std::cout << "Trying for Global :- " << ::reused << "\n";
    std::cout << "Trying for local :- " << reused << "\n";
    std::cout << "Hello, World!\n";

    int ival = 1024;
    int &refVal = ival;

    std::cout << refVal << "\n";
    ++ival;
    std::cout << refVal << "\n";
    ++refVal;
    std::cout << ival << "\n";
    std::cout << refVal << "\n";
    std::cout << "------------------------------------------------------------------------" << "\n";

    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    r2 = 3.14159f;
    std::cout << "d :- " << d << "\n";
    r2 = r1;
    std::cout << "d :- " << d << "\n";
    i = r2;
    std::cout << "i :- " << i << "\n";
    r1 = d;
    std::cout << "i :- " << i << "\n";

    std::cout << "----------------------2.17---------------------------------------------" << "\n";
    {
        int i, &ri = i;
        i = 5; ri = 10;
        std::cout << i << " " << ri << "\n";
    }
    return 0;
}
