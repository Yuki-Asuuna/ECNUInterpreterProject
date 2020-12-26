//
// Created by sunyh on 2020/12/26.
//

#include "MiddleVal.h"

MiddleVal::MiddleVal(Sym x) {
    Type=x.Type;
    dVal=x.dValue;
    iVal=x.iValue;
}

MiddleVal::MiddleVal(){
    Type = "real";
    int iVal = 0;
    double dVal = 0.0;
}


MiddleVal::MiddleVal(std::string type, std::string val) {
    Type=type;
    if(Type=="real"){
        dVal=str2double(val);
    }
    else{
        iVal=str2int(val);
    }
}

int MiddleVal::str2int(std::string str) {
    std::istringstream iss(str);
    int x;
    if (iss >> x)
        return x;
    return 0;
}


double MiddleVal::str2double(std::string str) {
    std::istringstream iss(str);
    double x;
    if (iss >> x)
        return x;
    return 0.0;
}

std::string MiddleVal::tostr() {
    if (Type == "real")
        return std::to_string(dVal);
    else
        return std::to_string(iVal);
}

MiddleVal &MiddleVal::operator *= (MiddleVal t) {
    double result, a, b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    result = a * b;
    if (Type == "real" || t.Type == "real") {
        Type = "real";
        dVal = result;
    } else {
        iVal = (int) result;
    }
    return *this;
}

MiddleVal &MiddleVal::operator/=(MiddleVal t) {
    double result, a, b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    result = a / b;
    if (Type == "real" || t.Type == "real") {
        Type = "real";
        dVal = result;
    } else {
        iVal = (int) result;
    }
    return *this;
}

MiddleVal &MiddleVal::operator-=(MiddleVal t) {
    double result, a, b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    result = a * b;
    if (Type == "real" || t.Type == "real") {
        Type = "real";
        dVal = result;
    } else {
        iVal = (int) result;
    }
    return *this;
}

MiddleVal &MiddleVal::operator+=(MiddleVal t) {
    double result, a, b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    result = a + b;
    if (Type == "real" || t.Type == "real") {
        Type = "real";
        dVal = result;
    } else {
        iVal = (int) result;
    }
    return *this;
}

bool MiddleVal::operator<(MiddleVal t) {
    double a,b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    return a<b;
}

bool MiddleVal::operator>(MiddleVal t) {
    double a,b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    return a>b;
}

bool MiddleVal::operator<=(MiddleVal t) {
    double a,b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    return a<=b;
}

bool MiddleVal::operator>=(MiddleVal t) {
    double a,b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    return a>=b;
}

bool MiddleVal::operator==(MiddleVal t) {
    double a,b;
    if (Type == "real") {
        a = dVal;
    } else {
        a = iVal;
    }
    if (t.Type == "real") {
        b = t.dVal;
    } else {
        b = t.iVal;
    }
    return fabs(a-b)<0.000001;
}

void MiddleVal::operator=(MiddleVal t) {
    Type=t.Type;
    iVal=t.iVal;
    dVal=t.dVal;
}