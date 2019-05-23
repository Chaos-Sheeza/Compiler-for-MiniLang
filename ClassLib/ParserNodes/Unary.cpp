#include "MainHeader.h"

Unary::Unary(Lexer l){
    t = l.getNextToken();
    expr = new Expression(l);
}