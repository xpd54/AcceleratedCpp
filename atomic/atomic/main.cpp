//
//  main.cpp
//  atomic
//
//  Created by RaviPrakash on 27/2/2024.
//

#include <iostream>
#include <thread>
#include <atomic>

int main(int argc, const char * argv[]) {
    /**
     when one thread do increment to sum other thread can read it and do the same.
     Here issue of read-modify-write keep sum inconsistent. On x86 built in type is atomic
     but here increment involves reading from main memory than saving it and same goes for other thread.
     Read write of sum goes following.
     Main Memory <-----> L3 cache <----------> L2 cache <----------> L1 cache <-------> CPU core 1 registers
     increment of variable happen in core 1 registers which go back witten down to main memory to read by thread 2.
     */
    /*
     making sum atomic won't affect with sum = sum +1;
     Even to sum is atomic between read from main and CPU core increment thread 2 can read up and make the changes.
     Or it can get over written.
     */
    std::atomic<int> sum = 0;
    auto function = [&sum](){
        for (int i = 0; i < 1000000; i++) {
            /**
             To make it work on different thread we need to make sure increment operation in whole is atomic
             as std::atomic override operator++ and operator+= which make sure it's increment is atomic.
             Using ++ or += will work as expected.
             */
//            sum = sum + 1;
            sum ++;
        }
    };
    
    std::thread thread1(function);
    std::thread thread2(function);
    
    thread1.join();
    thread2.join();
    std::cout << "sum :- " << sum << "\n";
    return 0;
}
