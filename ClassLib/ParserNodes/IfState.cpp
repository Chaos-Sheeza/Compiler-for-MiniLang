#include "MainHeader.h"

IfState::IfState(Lexer* l){
    if(l->getNextToken().token != CIRCLEOP_BRACKET){
        std::cerr << "Expected \"(\"" << "\n";
        exit(EXIT_FAILURE);
    }
    expr = new Expression(l);
    if(l->getNextToken().token != CIRCLECL_BRACKET){
        std::cerr << "Expected \")\"" << "\n";
        exit(EXIT_FAILURE);
    }
    ifBl = new Block(l);
    if(l->peekNextToken().token == ELSE_EXP){
        l->getNextToken();
        elseBl = new Block(l);
    }
}
