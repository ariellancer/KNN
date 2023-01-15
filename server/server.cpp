//
// Created by nisan on 1/1/23.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "extractFunc.h"
#include "knn_implement.h"

using namespace std;

int main(int argc, char **argv) {

    const int server_port = extractPort(argv[2]);  //the port
    vector<Vector> arrayOfVectors = initializingTheVectors(argv[1]); //all the vectors in the data
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    const int enable = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    while (true) {
        struct sockaddr_in client_sin = {0};
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
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
                //the real algo is here
                try {
                    vector<char *> vec1 = getVectorFromUser(buffer);
                    int numOfNeighbors = atoi(vec1.at(vec1.size() - 1));
                    vec1.pop_back();
                    Distance *func = getTheMethodOfDistance((vec1.at(vec1.size() - 1)));
                    vec1.pop_back();
                    vector<double> vec2;
                    for (int i = 0; i < vec1.size(); i++) {
                        char *ptr;
                        double num = strtod(vec1.at(i), &ptr);
                        vec2.push_back(num);
                    }
                    string type = Knn(numOfNeighbors, arrayOfVectors, vec2, func);
                    int type_len = type.length() + 1;
                    memset(buffer, 0, 4096);
                    strcpy(buffer, type.c_str());
                    int sent_bytes = (int) send(client_sock, buffer, type_len, 0);
                    if (sent_bytes < 0) {
                        perror("error sending to client");
                        break;
                    }
                }catch (exception e) {
                   // std::cout << e.what() << std::endl;
                    string type = "invalid input";
                    int type_len = type.length() + 1;
                    memset(buffer, 0, 4096);
                    strcpy(buffer, type.c_str());
                    int sent_bytes = (int) send(client_sock, buffer, type_len, 0);
                    if (sent_bytes < 0) {
                        perror("error sending to client");
                        break;
                    }
                }
            }
        }
    }

