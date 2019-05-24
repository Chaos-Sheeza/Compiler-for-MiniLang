#include "MainHeader.h"

Term::Term(Lexer* l){
    node1 = new Factor(l);
    while(l->peekNextToken().token == MULT_MULTOP || l->peekNextToken().token == DIV_MULTOP || l->peekNextToken().token == AND_MULTOP){
        pair< Token, Factor*> temp;
        temp.first = l->getNextToken();
        temp.second = new Factor(l);
        node2Set.push_back(temp);
    }
}