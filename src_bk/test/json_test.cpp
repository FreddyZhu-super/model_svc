//
// Created by Freddy Zhu on 2022/9/22.
//
#include <fstream>
#include <iostream>
#include "../../lib/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

int main(){

    std::ifstream i("test_read.json");
    json j;
    i >> j;
    for (auto& el : j.items()) {
        std::cout << el.key() << " : " << el.value() << "\n";
    }



    // write prettified JSON to another file
    std::ofstream o("test_write.json");
    o << j.dump(2) << std::endl;
//    o << std::setw(4) << j<< std::endl;

}
