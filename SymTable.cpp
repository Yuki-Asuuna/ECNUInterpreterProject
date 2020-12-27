//
// Created by sunyh on 2020/12/25.
//

#include "SymTable.h"
void SymTable::Print() {
    for(auto item : symtable){
        if(item.second.Type=="int")
            std::cout<<item.second.Name<<' '<<item.second.Type<<' '<<item.second.iValue<<std::endl;
        else
            std::cout<<item.second.Name<<' '<<item.second.Type<<' '<<item.second.dValue<<std::endl;
    }
}

void SymTable::AddSym(Sym t) {
    symtable[t.Name]=t;
}

void SymTable::UpdateSym(std::string var,MiddleVal val) {
    if(symtable.find(var)==symtable.end()){
        std::cout<<"Undefined variable:"<<var<<std::endl;
        exit(-1);
    }
    if(symtable[var].Type=="real"){
        symtable[var].dValue=val.dVal;
    } else{
        symtable[var].iValue=val.iVal;
    }
}

Sym SymTable::GetValue(std::string key) {
    Sym r=symtable[key];
    return r;
}