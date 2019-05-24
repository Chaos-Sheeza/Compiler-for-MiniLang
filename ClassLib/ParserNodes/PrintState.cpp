#include "MainHeader.h"

PrintState::PrintState(Lexer* l){
    l->getNextToken();
    expr = new Expression(l);
}