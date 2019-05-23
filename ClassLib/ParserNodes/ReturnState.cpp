#include "MainHeader.h"

ReturnState::ReturnState(Lexer l){
    l.getNextToken();
    expr = new Expression(l);
}