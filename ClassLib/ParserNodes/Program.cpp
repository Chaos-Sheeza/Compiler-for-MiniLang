#include "1MainHeader.h"

Program::Program(Lexer l){
    while(l.peekNextToken().token != NONTOKEN){
        statements.push_back(Statement(l));
    }
}
