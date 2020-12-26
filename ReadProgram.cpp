//
// Created by sunyh on 2020/11/16.
//

#include "ReadProgram.h"

std::string ReadProgram() {
    char *inputfilename = "test.txt";
    std::ifstream in;
    in.open(inputfilename);
    if (!in.is_open()) {//未能打开文件
        std::cout << "Failed to open file." << std::endl;
        return "";
    }
    char ch;
    std::string ret;
    while (in.get(ch)) {
        ret += ch;
    }
    return ret;
}

