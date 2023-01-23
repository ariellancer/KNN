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
#include "SocketIO.h"

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
    SocketIO *s = new SocketIO(port_no);
    while (true) {
        //print the manu
        string str = s->read();
        cout << str << endl;
        //scan the choice
        int choice;
        //int choice = stoi(s->read());
        cin >> choice;
        string receive, localTrain, localTest, parameters;
        char *str_inp1, *str_inp2;
        switch (choice) {

            case 1:
                s->write("1");
                receive = s->read();
                cout << receive << endl;
                //get the local train CSV file
                cin >> localTrain;
                s->write(localTrain);
                receive = s->read();
                cout << receive << endl;
                //if we receive invalid input than break.
                str_inp1 = "invalid input";
                str_inp2 = new char[receive.length() + 1];
                strcpy(str_inp2, receive.c_str());
                if (strcmp(str_inp1, str_inp2) == 0) {
                    break;
                }
                //get the local test CSV file
                receive = s->read();
                cout << receive << endl;
                cin >> localTest;
                s->write(localTest);
                //todo we need to send Upload complete also in the second time!!
                receive = s->read();
                cout << receive << endl;
                break;
            case 2:
                s->write("2");
                receive = s->read();
                cout << receive << endl;
                //get the KNN parameters
                cin >> parameters;
                s->write(parameters);
                receive = s->read();
                //if we receive invalid input than break.
                str_inp1 = "invalid value for K";
                str_inp2 = new char[receive.length() + 1];
                strcpy(str_inp2, receive.c_str());
                if (strcmp(str_inp1, str_inp2) == 0) {
                    cout << receive << endl;
                    receive = s->read();
                    str_inp1 = "invalid value for metric";
                    str_inp2 = new char[receive.length() + 1];
                    strcpy(str_inp2, receive.c_str());
                    if (strcmp(str_inp1, str_inp2) == 0) {
                        cout << receive << endl;
                    }else{
                        break;
                    }
                }
                str_inp1 = "invalid value for metric";
                str_inp2 = new char[receive.length() + 1];
                strcpy(str_inp2, receive.c_str());
                if (strcmp(str_inp1, str_inp2) == 0) {
                    cout << receive << endl;
                }
                break;
            case 3:
                s->write("3");
                receive = s->read();
                cout << receive << endl;
                break;
            case 4:
                s->write("4");
                receive = s->read();
                cout << receive << endl;
                if (cin.get() == '\n') {
                    break;
                }
            case 5:
                //todo
                s->write("5");
                break;
            case 8:
                // the server will close the connection
                s->write("8");
                break;
            default:
                // the server will send invalid option.
                s->write("9");
                receive = s->read();
                cout << receive << endl;
                break;
        }
    }
    close(sock);
    return 0;
}
    /*while (true){
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
}*/