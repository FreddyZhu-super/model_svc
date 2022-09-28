//
// Created by Freddy Zhu on 2022/9/28.
//

#ifndef MODEL_SVC_TEST_MAP_H
#define MODEL_SVC_TEST_MAP_H

#include <map>
#include <mutex>

class SafeMap {

private:
    std::mutex mut;
    std::map<int, int> m;
public:
    SafeMap() {
//        std::map<int, int> m;
//        std::mutex mut;
//        this->m = m;
//        this->mut = mut;
    };

    ~SafeMap() {
        std::map<int, int>::iterator it;
        std::map<int, int>::iterator itEnd = this->m.end();
        for (it = this->m.begin(); it != itEnd; it++) {
            it->second = 0;
        }
        this->m.clear();
    };

    void Set(int apiName, int algPtr) {
        this->mut.lock();
        this->m[apiName] = algPtr;
        this->mut.unlock();
    };

    void DeleteAndRelease(int apiName) {
        this->mut.lock();
        this->m.erase(apiName);
        this->mut.unlock();
    };

    // return null pointer if not exist
    int Get(int apiName) {
        this->mut.lock();
        int res = this->m[apiName];
        this->mut.unlock();
        return res;
    };


};


#endif //MODEL_SVC_TEST_MAP_H
