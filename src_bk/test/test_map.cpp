//
// Created by Freddy Zhu on 2022/9/23.
//
#include <string>
//#include <map>
#include <iostream>
#include <memory>
#include "test_map.h"

typedef std::shared_ptr<int> ptr;
static SafeMap sm;


int main() {
//    std::map <std::string, ptr> m;
//    ptr p1(new int(10086));
//    m["a"] = p1;
//    m["d"] = p1;
//    if (m["c"] == nullptr) {
////        std::cout << "map c is 0 " << std::endl;
//    }
//    std::cout << "map a: " << m["a"] << std::endl;
//    std::cout << "map b: " << m["b"] << std::endl;
//    std::cout << "map c: " << m["c"] << std::endl;
//    std::cout << "map d: " << m["d"] << std::endl;
//    std::cout << "ptr: " << p1 << std::endl;
//
//    m.erase("a");
//    m.erase("z");
//    std::cout << "\nafter" << std::endl;
//    std::cout << "map a: " << m["a"] << std::endl;
//    std::cout << "map d: " << m["d"] << std::endl;
//    std::cout << "ptr: " << p1 << std::endl;
//    p1 = nullptr;
//    std::cout << "set null ptr: " << p1 << std::endl;
//    std::cout << "map d: " << m["d"] << std::endl;

    std::cout << "sm:start " << std::endl;
    sm.Set(1,11);
    sm.Set(2,21);
    sm.Set(3,31);
    int r3 = sm.Get(3);
    std::cout << "map 3: " << r3 << std::endl;
    int r4 = sm.Get(4);
    std::cout << "map 4: " << r4 << std::endl;
    sm.DeleteAndRelease(3);
    int rr3 = sm.Get(3);
    std::cout << "map removed 3: " << rr3 << std::endl;
    sm.Set(3,32);
    int rsr3 = sm.Get(3);
    std::cout << "map reset 3: " << rsr3 << std::endl;

    std::cout << "smp start " << std::endl;
    smp->Set(3,31);
     r3 = smp->Get(3);
    std::cout << "map 3: " << r3 << std::endl;
     r4 = smp->Get(4);
    std::cout << "map 4: " << r4 << std::endl;
    smp->DeleteAndRelease(3);
    rr3 = smp->Get(3);
    std::cout << "map removed 3: " << rr3 << std::endl;
    smp->Set(3,32);
     rsr3 = smp->Get(3);
    std::cout << "map reset 3: " << rsr3 << std::endl;
}