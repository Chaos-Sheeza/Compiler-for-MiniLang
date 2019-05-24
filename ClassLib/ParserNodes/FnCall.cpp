#include "MainHeader.h"

FnCall::FnCall(Token prevT, Lexer* l){
    t = prevT;
    if(l->peekNextToken().token == CIRCLECL_BRACKET){
        l->getNextToken();
    }
    else
    {
        ap = new ActualParams(l);
        std::cout << l->peekNextToken().token << "\n";
        if(l->getNextToken().token != CIRCLECL_BRACKET){
            std::cerr << "Expected \")\"\n";
            exit(EXIT_FAILURE);
        }
    } 
}