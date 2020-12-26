//
// Created by sunyh on 2020/11/16.
//
#include "LexicalAnalyzer.h"


LexicalAnalyzer::LexicalAnalyzer(std::string &s) {
    source = s;
    KEYWORD["int"] = true;
    KEYWORD["real"] = true;
    KEYWORD["if"] = true;
    KEYWORD["then"] = true;
    KEYWORD["else"] = true;
    KEYWORD["while"] = true;
}

//Cut Line with '\n'
//And remove empty line
void LexicalAnalyzer::CutLine() {
    std::string line;
    source += '\n';//Add an '\n' at the end of file
    for (int i = 0; i < source.size(); i++) {
        if (source[i] != '\n') {
            line += source[i];
        } else {
            if (!line.empty()) {
                lines.push_back(line);
                line.clear();
            }
        }
    }
}

void LexicalAnalyzer::RemoveComment() {
    for (int i = 0; i < lines.size(); i++) {
        //std::cout<<lines[i]<<std::endl;
        int pos = lines[i].find("//");//double //
        if (pos != std::string::npos) {//Find double //
            lines[i].erase(pos);//Erase [pos,]
        }
    }
    // erase empty string in lines
    for (std::vector<std::string>::iterator iter = lines.begin(); iter != lines.end();) {
        if (iter->empty()) {
            lines.erase(iter);
        } else
            iter++;
    }
}

void LexicalAnalyzer::PrintLines() {
    for (int i = 0; i < lines.size(); i++) {
        std::cout << i << '\t' << lines[i] << std::endl;
    }
}

std::string LexicalAnalyzer::categorize(std::string &word) {
    if (KEYWORD[word]) {//keyword
        return "keyword";
    }
    //identifier
    std::regex pattern_id("[_a-zA-Z]\\w{0,63}");
    std::regex pattern_op("\\+|-|\\/|\\*|=|==|<|<=|>|>=|!=");
    std::regex pattern_del("\\(|\\)|\\{|\\}|\\;|\\,");
    std::regex pattern_num(
            "[0-9]+|\\.[0-9]+|[Ee][+-]{0,1}[0-9]+|[0-9]+[Ee][+-]{0,1}[0-9]+|[0-9]+\\.[0-9]+([Ee][+-]{0,1}[0-9]+){0,1}");
    if (std::regex_match(word, pattern_id)) {
        return "identifier";
    }
    if (std::regex_match(word, pattern_op)) {
        return "operator";
    }
    if (std::regex_match(word, pattern_del)) {
        return "delimiter";
    }
    if (std::regex_match(word, pattern_num)) {
        if(word.find('.')!=std::string::npos)
            return "real";
        else
            return "int";
    }
    return "error";
}

void LexicalAnalyzer::AddWord(std::string &w, int line) {
    if (!w.empty()) {
        //std::cout << w << ' ' << categorize(w) << ' ' << line << std::endl;
        quadraple tmp(categorize(w), w, line, 0);
        if(tmp.tokentype=="error"){
            error.push_back(tmp);
        }
        else
            result.push_back(tmp);
        w.clear();
    }
}

void LexicalAnalyzer::Parse() {
    for (int i = 0; i < lines.size(); i++) {
        std::string word;
        lines[i] += ' ';//temporary space
        for (int j = 0; j < lines[i].size(); j++) {
            char ch = lines[i][j];
            if (isdigit(ch) || isalpha(ch) || ch == '_' || ch == '.') {//digit,alpha,underline
                word += ch;
            } else if (ch == '-' || ch == '+') {
                //operator - or minus ?
                if (lines[i][j - 1] == 'e' || lines[i][j - 1] == 'E') {
                    word += ch;
                } else {
                    AddWord(word, i);
                    word += ch;
                    AddWord(word, i);
                }
            } else if (ch == '=' || ch == '<' || ch == '>' || ch == '!') {
                char peek = lines[i][j + 1];
                if ((ch == '=' && peek == '=') || (ch == '<' && peek == '=') || (ch == '>' && peek == '=') ||
                    (ch == '!' && peek == '=')) {
                    AddWord(word, i);
                    word += ch;
                    word += peek;
                    AddWord(word, i);
                    ++j;
                } else {
                    AddWord(word, i);
                    word += ch;
                    AddWord(word, i);
                }
            } else {//others
                AddWord(word, i);
                if (ch == ' ' || ch == '\t') continue;
                word += ch;
                AddWord(word, i);
            }
        }
    }
}

std::vector<quadraple> LexicalAnalyzer::GetResult() {
    std::cout<<"============================================================="<<std::endl;
    std::cout<<"Found "<<error.size()<<' '<<"lexical error(s)"<<std::endl;
    for(int i=0;i<error.size();i++){
        std::cout<<"At line "<<error[i].linenumber<<' '<<"position "<<error[i].lineposition<<':'<<error[i].attributevalue<<std::endl;
    }
    std::cout<<"============================================================="<<std::endl;
    int linepos = 0, lineid = 0;
    for (int i = 0; i < result.size(); i++) {
        if (result[i].linenumber == lineid) {
            result[i].lineposition = linepos;
            ++linepos;
        } else {
            result[i].lineposition = 0;
            linepos = 1;
            ++lineid;
        }
    }
    return result;
}


