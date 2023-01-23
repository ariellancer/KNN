//
// Created by ariel on 1/17/23.
//

#include "Standard_IO.h"
#include <iostream>

using namespace std;


std::string Standard_IO:: read(){
        string str;
        getline(cin,str);
        return str;
}
void Standard_IO:: write(std::string str){
    cout<<str<<endl;
}
void Standard_IO::Close() {
    return;
}
Standard_IO::Standard_IO() {
    return;
}


