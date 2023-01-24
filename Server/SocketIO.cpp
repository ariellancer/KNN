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
    string data,temp;
    char enter='\0';
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

        temp=buffer;
        temp = temp.substr(0,read_bytes);
        char c=buffer[read_bytes-1];
        if(c=='$'){
            buffer[read_bytes-1]='\0';
            temp=buffer;
            data=data.append(temp);
            return data;
        }
        data=data.append(temp);
        buffer[4096]={0};
    }
    return temp;
}

void SocketIO::write(std::string str) {
    string subString;
    int type_len,x,y,mini;

    while (str.length()>4095){
        subString=str.substr(0,4095);
        str=str.substr(4095);
        //   strcpy(buffer,subString.c_str());
        int sent_bytes = (int) send(client_sock, &(subString[0]), subString.size(), 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
            break;
        }
    }

    int sent_bytes = (int) send(client_sock, &(str[0]), str.size(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }



}
void SocketIO::Close() {
    close(this->client_sock);
}
