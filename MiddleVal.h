//
// Created by sunyh on 2020/12/26.
//

#ifndef PROJECT_MIDDLEVAL_H
#define PROJECT_MIDDLEVAL_H

#include <string>
#include <cmath>
#include "Sym.h"


class MiddleVal {
public:
    std::string Type;
    int iVal = 0;
    double dVal = 0.0;

    std::string tostr();
    double str2double(std::string);
    int str2int(std::string);

    MiddleVal(Sym);
    MiddleVal();
    MiddleVal(std::string,std::string);

    void operator = (MiddleVal t);

    MiddleVal &operator*=(MiddleVal t);
    MiddleVal &operator/=(MiddleVal t);
    MiddleVal &operator+=(MiddleVal t);
    MiddleVal &operator-=(MiddleVal t);

    bool operator > (MiddleVal t);
    bool operator >= (MiddleVal t);
    bool operator < (MiddleVal t);
    bool operator <= (MiddleVal t);
    bool operator == (MiddleVal t);
};


#endif //PROJECT_MIDDLEVAL_H
