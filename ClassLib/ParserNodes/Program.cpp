#include "MainHeader.h"

Program::Program(Lexer l){
    while(l.peekNextToken().token != NONTOKEN){
        statements.push_back(new Statement(l));
    }
}

void Program::accept(Visitor v){
    v.visit(this);
}

