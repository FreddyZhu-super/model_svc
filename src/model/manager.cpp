//
// Created by Freddy Zhu on 2022/9/21.
//
//#include "model_svc/lib/json/single_include/nlohmann/json.hpp"
#include <fstream>
#include <map>
#include <iostream>
#include <string>
//#include "../../lib/json/single_include/nlohmann/json.hpp"
#include "manager.h"
#include "model_common.h"
#include "include/rk3399/libai_core.hpp"
#include "include/rk3399/config.hpp"

using Model::Manager;
//using json = nlohmann::json;


static std::map<AlgoAPIName, string> modelMap;
static Model::AlgHandlerMap handlerMap;

//std::map<AlgoAPIName, string> ReadJson() {
//    std::ifstream json_file("model.json");
//    json json_read;
//    json model_json;
//    json_file >> json_read;
//    for (auto &el: json_read.items()) {
//        std::cout << el.key() << " : " << el.value() << "\n";
//        AlgoAPIName alg_name = (AlgoAPIName) stroi(el.key());
//        modelMap[alg_name] = el.value();
//    }
//    return modelMap;
//}
//
//
//Model::STATUS Manager::InitModelMap(std::string json_file_name) {
//    modelInfo = ReadJson();
//    return Model::SUCCESS;
//}

Model::STATUS Manager::InitModel(ucloud::AlgoAPIName apiName, std::map<int32_t, std::string> &modelPath) {
    ucloud::AlgoAPISPtr handler = handlerMap.Get(apiName);
    if (handler == nullptr) {
        return Model::SUCCESS
    }
    ucloud::AlgoAPISPtr algHandle = ucloud::AICoreFactory::getAlgoAPI(apiName);
    ucloud::RET_CODE ret = algHandle->init(modelPath);
    if (ret != ucloud::SUCCESS) {
        cout << "algorithm init error: " << ret << endl;
        return Model::ERROR
    } else {
        handlerMap.Set(apiName, algHandle);
    }
    return Model::SUCCESS;
}

Model::STATUS Manager::ReleaseModel(ucloud::AlgoAPIName apiName) {
    ucloud::AlgoAPISPtr algHandler = handlerMap.Get(apiName);
    if (algHandler == nullptr) {
        return Model::SUCCESS;
    }
    handlerMap.DeleteAndRelease(apiName)
    return Model::SUCCESS;
}

Model::STATUS
Manager::Inference(ucloud::AlgoAPIName apiName, InferenceParam *param, InferenceResult res) {
    ucloud::AlgoAPISPtr algHandler = handlerMap.Get(apiName);
    if (algHandler == nullptr) {
        return Model::ERROR_MODEL_NOT_INIT_YET
    }
    ucloud::RET_CODE retCode = algHandler->run(param->tvimage, res, param->threshold, param->nmsThreshold);
    if (retCode != ucloud::SUCCESS) {
        std::cout << RetCodeToString[retCode]<< std::endl;
        return Model::ERROR
    }

    return Model::SUCCESS;
}
