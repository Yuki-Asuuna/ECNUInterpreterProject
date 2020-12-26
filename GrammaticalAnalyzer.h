//
// Created by sunyh on 2020/11/19.
//
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include "LexicalAnalyzer.h"
#include <stack>
#include <fstream>

class LLGrammaticalAnalyzer {
private:
    std::set<std::string> VT;//Terminal symbol
    std::set<std::string> VN;//Non-Terminal symbol
    std::map<std::string, std::set<std::string> > FIRST, FOLLOW;
    std::multimap<std::string, std::vector<std::string> > P;//production rules
    std::string START;// Start symbol
    std::vector < std::pair < std::string, std::vector<std::string> > > VectorP;
    std::map <std::string, std:: map <std::string,int> > TABLE;// LL(1) TALBE

public:
    LLGrammaticalAnalyzer();

    void PrintProductionRules();
    void PrintFIRST();
    void PrintFOLLOW();

    void CalcFIRST();
    void CalcFOLLOW();
    void CreateTABLE();
    void AnalyzeToken(std::vector <quadraple> &);
    int CalcFIRSTSIZE();
    int CalcFOLLOWSIZE();
};

class LRGrammaticalAnalyzer{
private:
    static const int state_num=58;
    std::set<std::string> VT;//Terminal symbol
    std::set<std::string> VN;//Non-Terminal symbol
    std::map<std::string, std::set<std::string> > FIRST, FOLLOW;
    std::multimap<std::string, std::vector<std::string> > P;//production rules
    std::string START;// Start symbol
    std::map <std::string,std::string> ACTION[state_num];
    std::map<std::string,int> GOTO[state_num];
    std::vector < std::pair < std::string, std::vector<std::string> > > VectorP;
public:
    LRGrammaticalAnalyzer();
    void AnalyzeToken(std::vector <quadraple> &);
    void PrintStack(std::vector<quadraple> &,int ,std::stack<int> ,std::stack<std::string>);
};