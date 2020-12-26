//
// Created by sunyh on 2020/12/25.
//

#ifndef PROJECT_SYM_H
#define PROJECT_SYM_H

#include <string>
#include <sstream>

class Sym{
public:
    std::string Name;
    std::string Type;
    int iValue=0;
    double dValue=0.0;
    Sym(std::string,std::string,std::string);
    Sym();
    double str2double(std::string);
    int str2int(std::string);
   // std::string double2str(double);
};


#endif //PROJECT_SYM_H
