//
// Created by ariel on 1/18/23.
//

#include "SocketIO.h"
#include "string.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

SocketIO::SocketIO(int portNum) {
    this->client_sock=portNum;
}


std::string SocketIO::read() {
    string data;
    char *enter="\n";
    char buffer[4096] = {0};
    while (true) {
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            close(client_sock);
            break;
        }
        if (read_bytes < 0) {
            perror("Failed to receive from customer!");
            break;
        }
        char *c=&buffer[read_bytes-1];
        if(strcmp(c,"$")==0){
            (*c)=(*enter);
            data=data.append(buffer);
            return data;
        }
        data=data.append(buffer);
    }
}

void SocketIO::write(std::string str) {
    string subString;
    int type_len;
    char buffer[4096] = {0};
    //memset(buffer, 0, 4096);
    for(int i=0;i<=str.length();i+4096){
        subString=str.substr(i,i+4096);
        type_len=subString.length()+1;
        strcpy(buffer,subString.c_str());
        int sent_bytes = (int) send(client_sock, buffer, type_len, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
            break;
        }
    }

}
void SocketIO::Close() {
    close(this->client_sock);
}