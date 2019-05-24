#include "MainHeader.h"

Expression::Expression(Lexer* l){
    node1 = new SimpleExpr(l);
    while(l->peekNextToken().token == GREAT_RELOP || l->peekNextToken().token == SMALL_RELOP || l->peekNextToken().token == EQ_RELOP || l->peekNextToken().token == NOTEQ_RELOP || l->peekNextToken().token == GREATEQ_RELOP || l->peekNextToken().token == SMALLEQ_RELOP){
        pair <Token, SimpleExpr*> temp;
        temp.first = l->getNextToken();
        temp.second = new SimpleExpr(l);
        node2Set.push_back(temp);
    }
}