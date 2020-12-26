//
// Created by sunyh on 2020/12/25.
//

#ifndef PROJECT_SYMTABLE_H
#define PROJECT_SYMTABLE_H

#include <string>
#include <iostream>
#include <map>
#include "Sym.h"
#include "MiddleVal.h"
class SymTable{
private:
    std::map <std::string,Sym> symtable;
public:
    void UpdateSym(std::string,MiddleVal);
    void AddSym(Sym);
    void Print();
    Sym GetValue(std::string);
};


#endif //PROJECT_SYMTABLE_H
