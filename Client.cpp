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
#include "Server/extractFunc.h"
#include "Server/SocketIO.h"
#include "Server/Standard_IO.h"
#include <fstream>
#include <cstdlib>
#include <thread>

using namespace std;
using std::ofstream;

    void run(string receive,string path ){
      fstream stream;
      string token,delimiter="\n";
      size_t pos=0;
      stream.open(path,ios::out);
 //todo
 
      while ((pos=receive.find(delimiter))!= std::string::npos){
         token=receive.substr(0,pos);
         stream<<token<<endl;
         receive.erase(0,pos+delimiter.length());
        }
                  //  stream<<receive<<endl;
      stream.close();


}


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
    Standard_IO *prints=new Standard_IO();
    SocketIO *socketIo = new SocketIO(sock);
    string menu = socketIo->read();
    int choice;
    while (true) {
        //print the manu
       // string menu = s->read();
        prints->write(menu);
        //scan the choice
        string input=prints->read();
   try {
       choice= stoi(input);
   }catch (exception e){
       prints->write("invalid input");
       break;
   }
   int counter=0;
        ifstream infile,testfile;
         fstream stream;
        string receive, localTrain, localTest, parameters,temp,temp2,line,path,token,delimiter="\n";
        size_t pos=0;
       // thread run1;
        char *str_inp1, *str_inp2;
        switch (choice) {

            case 1:
                socketIo->write("1$");
                receive = socketIo->read();
                prints->write(receive);
                localTrain=prints->read();

                //get the local train CSV file
                infile.open(localTrain);
                if(!infile){
                    prints->write("invalid input");
                    socketIo->write("close$");
                    break;
                }
                while (getline(infile,line)){
                  //  line.append("\n");
                    temp=temp.append(line);
                    temp=temp.append("\n");
                    counter++;
                  //  socketIo->write("\n");
                }
                temp=temp.append("$");
                socketIo->write(temp);

                //socketIo->write("$");
                receive = socketIo->read();
                if (receive.compare("invalid input")==0){
                    prints->write(receive);
                    break;
                }
                prints->write(receive);
                // ack on first part
                socketIo->write("$");
                //next part
                receive=socketIo->read();
                prints->write(receive);
                localTest=prints->read();
                testfile.open(localTest);
                if(!testfile){
                    prints->write("invalid input");
                    socketIo->write("close$");

                    break;
                }
                while (getline(testfile,line)){
                    temp2=temp2.append(line);
                    temp2=temp2.append("\n");
                    counter++;

                   // socketIo->write("\n");
                }
                socketIo->write(temp2);
                socketIo->write("$");
                receive = socketIo->read();
                if (receive.compare("invalid input")==0){
                    prints->write(receive);
                    break;
                }
                break;


            case 2:
                socketIo->write("2$");
                receive = socketIo->read();
                prints->write(receive);
                //get the KNN parameters
                parameters= prints->read();
                socketIo->write(parameters);
                socketIo->write("$");
                receive = socketIo->read();
                if(receive.compare("")==0){
                    break;
                } else{
                    prints->write(receive);
                    break;
                }



            case 3:
                socketIo->write("3$");
                receive = socketIo->read();
                prints->write(receive);
                break;
            case 4:
                socketIo->write("4$");
                receive = socketIo->read();
                prints->write(receive);
                if(receive.compare("please upload data")==0){
                    break;
                }
                receive=prints->read();
                break;
            case 5:
                //todo
                socketIo->write("5$");              
                receive= socketIo->read();
                if(receive.compare("")==0){
                    path=prints->read();
                    stream.open(path,ios::out);
                if (!stream){
                    socketIo->write("close$");
                    prints->write("invalid input");
                    break;
                }
                socketIo->write("$");
                receive=socketIo->read();
                thread run1(run,receive,path);
                run1.detach();
                

                } else{
                    prints->write(receive);
                }

                break;
            case 8:
                // the server will close the connection
                socketIo->write("8$");
                close(sock);
                return 0;
            default:
                // the server will send invalid option.
                socketIo->write("9$");
                receive = socketIo->read();
                prints->write(receive);

                break;
        }
    }

}
