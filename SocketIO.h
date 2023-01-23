//
// Created by ariel on 1/18/23.
//
#include "DefaultIO.h"
#ifndef ASS_41_SOCKETIO_H
#define ASS_41_SOCKETIO_H


class SocketIO:public DefaultIO {
private:
    int client_sock;
public:
    std::string read() override;
    void write(std::string str) override;
    SocketIO(int portNum);
    void Close() override;

};


#endif //ASS_41_SOCKETIO_H
