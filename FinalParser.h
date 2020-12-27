#include <vector>
#include "quadraple.h"
#include "SymTable.h"
#include "MiddleVal.h"

class FinalParser {

private:
    std::vector <quadraple> token;
    SymTable table;
    int index=-1;

public:
    FinalParser(std::vector <quadraple> );
    void ProcessDecl();
    void PrintSymtable();
    void match(std::string);
    std::string getnow();
    MiddleVal term();
    MiddleVal factor();
    MiddleVal expression();
    MiddleVal statement();
    int boolexp();
    int boolOR();
    int boolAND();
    void skipstatement();
    void Start();
};