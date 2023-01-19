//
// Created by ariel on 1/18/23.
//

#include "SocketIO.h"
#include "string.h"

using namespace std;

SocketIO::SocketIO(int portNum) {
    this->client_sock=portNum;
}


std::string SocketIO::read() {
    string data;
    char buffer[4096] = {0};
    while (true) {
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            //close(client_sock);
            break;
        }
        if (read_bytes < 0) {
            perror("Failed to receive from customer!");
            break;
        }
        if(strcmp(buffer[read_bytes-1],"$")==0){
            buffer[read_bytes-1]="\n";
            data=data.append(buffer);
            return data;
        }
        data=data.append(buffer);
    }
}

void SocketIO::write(std::string str) {
    string subString;
    char buffer[4096] = {0};
    //memset(buffer, 0, 4096);
    for(int i=0;i<=str.length();i+4096){
        subString=str.substr(i,,i+4096);
        strcpy(buffer,subString.c_str());
        int sent_bytes = (int) send(client_sock, buffer, type_len, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
            break;
        }
    }

}