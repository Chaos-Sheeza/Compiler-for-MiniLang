#include "MainHeader.h"

ActualParams::ActualParams(Lexer* l){
    expr = new Expression(l);
    while(l->peekNextToken().token != CIRCLECL_BRACKET){
        if(l->getNextToken().token != COMMA_PUNCT){
            std::cerr << "Missing ,\n";
            exit(EXIT_FAILURE);
        }
        exprSet.push_back(new Expression(l));
    }    
}