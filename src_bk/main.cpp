#include <iostream>
#include "model/manager.h"


int main() {
    Model_manager::manager manager;
    Model_manager::STATUS s = manager.run();
    if (s != Model_manager::SUCCESS) {
        std::cout << " manager run failed " << std::endl;
    }

}