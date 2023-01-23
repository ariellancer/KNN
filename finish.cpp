//
// Created by ariel on 1/17/23.
//

#include "finish.h"

finish::finish(){
    setDescription("8. exit");
}

void finish:: execute(){
    dio->Close();
}