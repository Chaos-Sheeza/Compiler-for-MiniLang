#include "MainHeader.h"

FormalParam::FormalParam(Lexer l){
    if(l.peekNextToken().token != VARNAME_DEC){
        std::cerr << "Invalid identifier" << "\n";
        exit(EXIT_FAILURE);
    }
    id = l.getNextToken();
    if(l.getNextToken().token != COL_PUNCT){
        std::cerr << "Missing :" << "\n";
        exit(EXIT_FAILURE);
    }
    if(l.peekNextToken().token != INT_TYPE || l.peekNextToken().token != FLOAT_TYPE || l.peekNextToken().token != BOOL_TYPE){
        std::cerr << "Invalid type" << "\n";
        exit(EXIT_FAILURE);
    }
    type = l.getNextToken();
}