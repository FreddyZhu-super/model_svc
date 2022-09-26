//
// Created by Freddy Zhu on 2022/9/23.
//
#include <string>
#include <map>
#include <iostream>
#include <memory>

typedef std::shared_ptr<int> ptr;

int main() {
    std::map <std::string, ptr> m;
    ptr p1(new int(10086));
    m["a"] = p1;
    m["d"] = p1;
    if (m["c"] == nullptr) {
//        std::cout << "map c is 0 " << std::endl;
    }
    std::cout << "map a: " << m["a"] << std::endl;
    std::cout << "map b: " << m["b"] << std::endl;
    std::cout << "map c: " << m["c"] << std::endl;
    std::cout << "map d: " << m["d"] << std::endl;
    std::cout << "ptr: " << p1 << std::endl;

    m.erase("a");
    m.erase("z");
    std::cout << "\nafter" << std::endl;
    std::cout << "map a: " << m["a"] << std::endl;
    std::cout << "map d: " << m["d"] << std::endl;
    std::cout << "ptr: " << p1 << std::endl;
    p1 = nullptr;
    std::cout << "set null ptr: " << p1 << std::endl;
    std::cout << "map d: " << m["d"] << std::endl;
}