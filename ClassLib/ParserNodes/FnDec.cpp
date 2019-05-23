#include "MainHeader.h"

FnDec::FnDec(Lexer l){
    l.getNextToken();
    if(l.peekNextToken().token != VARNAME_DEC){
        std::cerr << "Incorrect function name" << "\n";
        exit(EXIT_FAILURE);
    }
    id = l.getNextToken();
    if(l.getNextToken().token != CIRCLEOP_BRACKET){
        std::cerr << "Missing (" << "\n";
        exit(EXIT_FAILURE);
    }
    if(l.peekNextToken().token != CIRCLEOP_BRACKET){
        param = new FormalParams(l);
    }
    if(l.getNextToken().token != CIRCLECL_BRACKET){
        std::cerr << "Missing )" << "\n";
        exit(EXIT_FAILURE);
    }
    if(l.getNextToken().token != COL_PUNCT){
        std::cerr << "Missing :" << "\n";
        exit(EXIT_FAILURE);
    }
    if(l.peekNextToken().token != INT_TYPE || l.peekNextToken().token != FLOAT_TYPE || l.peekNextToken().token != BOOL_TYPE){
        std::cerr << "Invalid type" << "\n";
        exit(EXIT_FAILURE);
    }
    type = l.getNextToken();
    bl = new Block(l);
}