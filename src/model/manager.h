//
// Created by Freddy Zhu on 2022/9/21.
//

#ifndef MODEL_SVC_MANAGER_H
#define MODEL_SVC_MANAGER_H

#include <string>
#include "../common/model_common.h"
#include "../../lib/ucloud_cambricon_sdk/libai_core.hpp"
#include "../../lib/ucloud_cambricon_sdk/config.hpp"

namespace Algorithm {
    typedef struct InferenceParam {
        float threshold;
        float nmsThreshold;
        unsigned char *pData;
        ucloud::VecObjBBox &bboxes;
        ucloud::TvaiImage &tvimage;
    } InferenceParam;

    typedef struct InferenceResult {
        ucloud::BBox bBox;
        std::string errMsg;
        bool success;
    } InferenceResult;


    class Manager {
    public:
        STATUS InitModelMap(std::string jsonName);

        STATUS InitModel(std::string modelName);

        STATUS ReleaseModel(std::string modelName);

        STATUS Inference(InferenceParam *param, InferenceResult *res);

    private:

    };


    class AlgHandlerMap {

    private:
        std::mutex mut;
        std::map <ucloud::AlgoAPIName, ucloud::AlgoAPISPtr> m;
    public:
        AlgHandlerMap();

        ~AlgHandlerMap() {
            std::map<ucloud::AlgoAPIName, ucloud::AlgoAPISPtr>::iterator it;
            std::map<ucloud::AlgoAPIName, ucloud::AlgoAPISPtr>::iterator itEnd = this->m.end();
            for (it = this->m.begin(); it != itEnd; it++) {
                it->second = nullptr;
            }
            this->m.clear();
        };

        void Set(ucloud::AlgoAPIName apiName, ucloud::AlgoAPISPtr algPtr) {
            this->mut.lock();
            this->m.insert(apiName, algPtr);
            this->mut.unlock();
        };

        void DeleteAndRelease(ucloud::AlgoAPIName apiName) {
            this->mut.lock();
            ucloud::AlgoAPISPtr h = this->m[apiName];
            this->m.erase(apiName);
            this->mut.unlock();
            h = nullptr
        };

        AlgoAPISPtr Get(AlgoAPIName apiName) {
            this->mut.lock();
            ucloud::AlgoAPISPtr res = this->m[apiName];
            this->mut.unlock();
            return res
        };


    };
};




std::map<ucloud::RET_CODE:std::string>
ret_code_to_string =
        {
                {ucloud::SUCCESS,                    "success"},
                {ucloud::FAILED,                     "failed for unknown reason"},
                {ucloud::ERR_MLU_INIT_FAILED,        "MLU init failed"},
                {ucloud::ERR_MODEL_FILE_NOT_EXIST,   "model file not found"},
                {ucloud::ERR_INIT_PARAM_FAILED,      "wrong init parameters"},
                {ucloud::ERR_UNSUPPORTED_IMG_FORMAT, "imported wrong format image"},
                {ucloud::ERR_MODEL_NOT_MATCH,        "model not matched"},
                {ucloud::ERR_MODEL_NOT_INIT,         "model is not load yet, please init it at first"},
                {ucloud::ERR_OUTPUT_CLS_INIT_FAILED, "cannot bind correct CLS_TYPES "},
                {ucloud::ERR_BATCHSIZE_NOT_MATCH,    "data batch size should be matched with model"},
                {ucloud::ERR_PHYADDR_EMPTY,          "empty physical addr"},
                {ucloud::ERR_VIRTUAL_FUNCTION,       "class not support with such virtual func"},
                {ucloud::ERR_EMPTY_BOX,              "imported bbox cannot be empty"},
        };


#endif //MODEL_SVC_MANAGER_H