//
// Created by sunyh on 2020/12/25.
//

#include "Sym.h"


double Sym::str2double(std::string str) {
    std::istringstream iss(str);
    double x;
    if (iss >> x)
        return x;
    return 0.0;
}

int Sym::str2int(std::string str) {
    std::istringstream iss(str);
    int x;
    if (iss >> x)
        return x;
    return 0;
}

Sym::Sym(std::string type, std::string name, std::string value) {
    Name = name;
    Type = type;
    if (type == "real") {
        dValue = str2double(value);
    } else {//int
        iValue = str2int(value);
    }
}

Sym::Sym(){

}