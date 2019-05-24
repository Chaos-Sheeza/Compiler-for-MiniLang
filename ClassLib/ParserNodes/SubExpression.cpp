#include "MainHeader.h"

SubExpression::SubExpression(Lexer* l){
    l->getNextToken();
    expr = new Expression(l);
    if(l->getNextToken().token != CIRCLECL_BRACKET){
        std::cerr << "Missing )" << "\n";
        exit(EXIT_FAILURE);
    }
}