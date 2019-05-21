#include "1MainHeader.h"

VarDec::VarDec(Lexer l){
    Token t = l.getNextToken();
    if (t.token != VARNAME_DEC)
    {
        std::cerr << "Invalid variable name" << "\n";
        exit(EXIT_FAILURE);
    }
    iden = t;
    t = l.getNextToken();
    if (t.token != COL_PUNCT)
    {
        std::cerr << "Colon expected" << "\n";
        exit(EXIT_FAILURE);
    }
    t = l.getNextToken();
    if (t.token != FLOAT_TYPE || t.token != INT_TYPE || t.token != BOOL_TYPE)
    {
        std::cerr << "Invalid variable type" << "\n";
        exit(EXIT_FAILURE);
    }
    type = t;
    t = l.getNextToken();
    if (t.token != EQ_DEC)
    {
        std::cerr << "Equals expected" << "\n";
        exit(EXIT_FAILURE);
    }
    e = new Expression(l);
}