//
// Created by Freddy Zhu on 2022/9/21.
//
//#include "model_svc/lib/json/single_include/nlohmann/json.hpp"
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include "../../lib/json/single_include/nlohmann/json.hpp"
#include "manager.h"
#include "../common/model_common.h"
#include "../../lib/ucloud_cambricon_sdk/libai_core.hpp"
#include "../../lib/ucloud_cambricon_sdk/config.hpp"

using Algorithm::Manager;
using json = nlohmann::json;


static std::map<AlgoAPIName, string> modelMap;
static AlgHandlerMap algHandlerMap;

std::map<AlgoAPIName, string> ReadJson() {
    std::ifstream json_file("model.json");
    json json_read;
    json model_json;
    json_file >> json_read;
    for (auto &el: json_read.items()) {
        std::cout << el.key() << " : " << el.value() << "\n";
        AlgoAPIName alg_name = (AlgoAPIName) stroi(el.key());
        model_map[alg_name] = el.value();
    }
    return model_map;
}


Algorithm::STATUS manager::InitModelMap(std::string json_file_name) {
    modelInfo = ReadJson();
    return Algorithm::SUCCESS;
}

Algorithm::STATUS manager::InitModel(ucloud::AlgoAPIName apiName) {
    ucloud::AlgoAPI alg_api;
    ucloud::AlgoAPISPtr algHandle = ucloud::AICoreFactory::getAlgoAPI(apiName);
    ret = algHandle->init(modelMap[apiName]);
    if (ret != ucloud::SUCCESS) {
        cout << "algorithm init return " << ret << endl;
        return ERROR
    } else {
        algHandlerMap->Set(apiName, algHandle);
    }
    return Algorithm::SUCCESS;
}

Algorithm::STATUS manager::ReleaseModel(ucloud::AlgoAPIName apiName) {
    ucloud::AlgoAPISPtr algHandler = algHandlerMap->Get(apiName);
    if (algHandler == nullptr) {
        return Algorithm::SUCCESS;
    }
    algHandlerMap->DeleteAndRelease(apiName)
    return Algorithm::SUCCESS;
}

Algorithm::STATUS
Manager::Inference(ucloud::AlgoAPIName apiName, InferenceParam *param, InferenceResult *res) {
    ucloud::AlgoAPISPtr algPtr = algHandlerMap->Get(apiName);
    algPtr->run(param->tvimage, param->bboxes)
    return Algorithm::SUCCESS;
}
