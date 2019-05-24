#include "MainHeader.h"

ForState::ForState(Lexer* l){
    if(l->getNextToken().token != CIRCLEOP_BRACKET){
        std::cerr << "Incorrect start of for expression" << "\n";
        exit(EXIT_FAILURE);
    }
    if(l->peekNextToken().token == VAR_DEC){
        l->getNextToken();
        vr = new VarDec(l);
    }
    if(l->getNextToken().token != SEMICOL_PUNCT){
        std::cerr << "Missing ;" << "\n";
        exit(EXIT_FAILURE);
    }
    ex = new Expression(l);
    if(l->getNextToken().token != SEMICOL_PUNCT){
        std::cerr << "Missing ;" << "\n";
        exit(EXIT_FAILURE);
    }
    if(l->peekNextToken().token != CIRCLECL_BRACKET){
        at = new Assignment(l);
    }
    if(l->getNextToken().token != CIRCLECL_BRACKET){
        std::cerr << "Missing )" << "\n";
        exit(EXIT_FAILURE);
    }
    bl = new Block(l);
}