//
// Created by sunyh on 2020/12/25.
//

#include "FinalParser.h"
#include "Sym.h"
#include "MiddleVal.h"

FinalParser::FinalParser(std::vector<quadraple> tk) {
    token = tk;
}

void FinalParser::PrintSymtable() {
    table.Print();
}


void FinalParser::ProcessDecl() {

    for (int i = 0; i < token.size(); i++) {
        if (token[i].attributevalue == "{") {
            index = i;
            return;
        } else if (token[i].attributevalue == "real" || token[i].attributevalue == "int") {
            Sym newsym(token[i].attributevalue, token[i + 1].attributevalue, token[i + 3].attributevalue);
            table.AddSym(newsym);
        }
    }
}

void FinalParser::Start() {
    statement();
}


std::string FinalParser::getnow() {
    std::string val;
    if (token[index].tokentype == "identifier")
        val = "ID";
    else if (token[index].tokentype == "real")
        val = "real";
    else if (token[index].tokentype == "int")
        val = "int";
    else
        val = token[index].attributevalue;
    return val;
}


void FinalParser::match() {
    ++index;
    if (index >= token.size()) {
        std::cout << "Success!" << std::endl;
        PrintSymtable();
        exit(0);
    }
}


MiddleVal FinalParser::expression() {
    MiddleVal temp = term();
    std::string tk = getnow();
    while (tk == "+" || tk == "-") {
        if (tk == "+") {
            match();
            temp += term();
        } else {
            match();
            temp -= term();
        }
        tk = getnow();
    }
    return temp;
}

MiddleVal FinalParser::factor() {
    std::string tk = getnow();
    MiddleVal temp;
    if (tk == "(") {
        match();
        temp = expression();
        match();
    } else if (tk == "int" || tk == "real") {
        //token[index].attributevalue
        temp = MiddleVal(tk, token[index].attributevalue);
        match();
    } else if (tk == "ID") {
        Sym t = table.GetValue(token[index].attributevalue);
        temp = MiddleVal(t);
        match();
    }
    return temp;
}


MiddleVal FinalParser::term() {
    MiddleVal temp = factor();
    std::string tk = getnow();
    while (tk == "*" || tk == "/") {
        if (tk == "*") {
            match();
            temp *= factor();
        } else {
            match();
            temp /= factor();
        }
        tk = getnow();
    }
    return temp;
}

int FinalParser::boolAND() {
    int val = boolexp();
    std::string tk = getnow();
    while (tk == "&&") {
        match();
        if (val == 0) return 0;         // short cut
        val = val & boolexp();
        if (val == 0) return 0;
    }
    return val;
}


int FinalParser::boolOR() {
    int val = boolAND();
    std::string tk = getnow();
    while (tk == "||") {
        match();
        if (val == 1) return 1;         // short cut
        val = val | boolAND();
    }
    return val;
}

int FinalParser::boolexp() {
    std::string tk = getnow();
    if (tk == "(") {
        match();
        int result = boolOR();
        match();
        return result;
    }
    MiddleVal temp = expression();
    tk = getnow();
    if (tk == ">") {
        match();
        return temp > expression();
    } else if (tk == "<") {
        match();
        return temp < expression();
    } else if (tk == ">=") {
        match();
        return temp >= expression();
    } else if (tk == "<=") {
        match();
        return temp <= expression();
    } else if (tk == "==") {
        match();
        return temp == expression();
    }
    return 0;
}

void FinalParser::skipstatement() {
    if (getnow() == "{") {
        match();
        int count = 0;
        while (1) {
            if (count == 0 && getnow() == "}") {
                match();
                break;
            }
            if (getnow() == "{") ++count;
            else if (getnow() == "}") --count;
            match();
        }

    } else {//assgstmt or other
        while (getnow() != ";") {
            match();
        }
        match();//';'
    }

}

MiddleVal FinalParser::statement() {
    std::string tk = getnow();
    if (tk == "{") {
        match();
        while (getnow() != "}") {
            statement();
        }
        match();
    } else if (tk == "if") {
        match();//'if'
        match();//'('
        int boolresult = boolOR();
        match();//')'
        match();//'then'
        if (boolresult) {
            statement();
        } else {
            skipstatement();
        }
        tk = getnow();
        if (tk == "else") {
            match();//'else'
            if (!boolresult) {
                statement();
            } else {
                skipstatement();
            }
        }
    } else if (tk == "ID") {
        std::string varname = token[index].attributevalue;
        match();//'ID'
        match();//'='
        //std::cout<<"*";
        MiddleVal exp = expression();
        table.UpdateSym(varname, exp);
        match();//';'
    }
    return MiddleVal();
}