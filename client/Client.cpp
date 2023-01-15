//
// Created by ariel on 1/2/23.
//


#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sstream>
#include "extractFunc.h"

using namespace std;



int main(int argc,char **argv){


    const char* ip_address= argv[1];
    int port=extractPort(argv[2]);
    const int port_no= port;
    int sock= socket(AF_INET, SOCK_STREAM,0);
    if (sock<0){
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family= AF_INET;
    sin.sin_addr.s_addr= inet_addr(ip_address);
    sin.sin_port= htons(port_no);
    if (connect(sock,(struct sockaddr*)&sin, sizeof(sin))<0){
        perror("error connecting to server");
        return 0;
    }

    while (true){
        cout<<"write data:\n";
        string str;
        getline(cin,str);
        if(stop(str)){
            close(sock);
            return 0;
        }
        char data_addr[str.length()+1];
        strcpy(data_addr,str.c_str());
        int data_len=str.length()+1;
        //char *data_addr=(char*) (str.c_str());
        //int data_len= strlen(data_addr);
        int sent_bytes= send(sock, data_addr, data_len,0);
        if (sent_bytes<0){
            perror("error sending to server");
        }

        char buffer[4096];
        int expected_data_len= sizeof(buffer);
        int read_bytes= recv(sock, buffer, expected_data_len,0);
        if (read_bytes<0){
            perror("error getting from server");
        }
        else{
            cout << buffer<<"\n";
        }
    }
    return 0;
}