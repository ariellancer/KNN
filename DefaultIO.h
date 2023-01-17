//
// Created by ariel on 1/15/23.
//

#ifndef ASS_4_DEFAULTIO_H
#define ASS_4_DEFAULTIO_H

class DefaultIO{
public:
    virtual strd::string read()=0;
    virtual void write(std::string str)=0;
};


#endif //ASS_4_DEFAULTIO_H
