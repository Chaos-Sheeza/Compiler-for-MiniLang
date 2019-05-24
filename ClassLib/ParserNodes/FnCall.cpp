#include "MainHeader.h"

FnCall::FnCall(Token prevT, Lexer* l){
    t = prevT;
    if(l->peekNextToken().token == CIRCLECL_BRACKET){
        l->getNextToken();
    }
    else
    {
        ap = new ActualParams(l);
        if(l->peekNextToken().token != CIRCLECL_BRACKET){
            std::cerr << "Expected \")\"";
            exit(EXIT_FAILURE);
        }
    } 
}