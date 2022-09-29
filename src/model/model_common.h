//
// Created by Freddy Zhu on 2022/9/22.
//

#ifndef MODEL_SVC_MODEL_COMMON_H
#define MODEL_SVC_MODEL_COMMON_H

namespace Model {
    //if func returns STATUS, caller should check STATUS if SUCCESS,
    //if SUCCESS, process the real return variable 'res', which passed its ptr into the func,
    //otherwise, handle the error.
    typedef enum STATUS {
        SUCCESS = 0,
        ERROR = 1,
        ERROR_MODEL_NOT_INIT_YET = 2,
    } STATUS;


}

#endif //MODEL_SVC_MODEL_COMMON_H
