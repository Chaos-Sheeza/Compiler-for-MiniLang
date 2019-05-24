#include "MainHeader.h"

Assignment::Assignment(Lexer* l){
    if(l->peekNextToken().token != VARNAME_DEC){
        std::cerr << "Incorrect variable name" << "\n";
        exit(EXIT_FAILURE);
    }
    t = l->getNextToken();
    if(l->getNextToken().token != EQ_DEC){
        std::cerr << "Missing =" << "\n";
        exit(EXIT_FAILURE);
    }
    exp = new Expression(l);
}