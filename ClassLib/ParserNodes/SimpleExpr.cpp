#include "MainHeader.h"

SimpleExpr::SimpleExpr(Lexer* l){
    node1 = new Term(l);
    while(l->peekNextToken().token == ADD_ADDOP || l->peekNextToken().token == SUB_ADDOP || l->peekNextToken().token == OR_ADDOP){
        pair< Token, Term*> temp;
        temp.first = l->getNextToken();
        temp.second = new Term(l);
        node2Set.push_back(temp);
    }
}