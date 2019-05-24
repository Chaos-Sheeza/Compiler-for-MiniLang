#include "MainHeader.h"

Factor::Factor(Lexer* l){
    if (l->peekNextToken().token == NUMBER_DEC || l->peekNextToken().token == TRUE_BOOLLIT || l->peekNextToken().token == FALSE_BOOLLIT){
        t = l->getNextToken();
    }
    else if(l->peekNextToken().token == VARNAME_DEC){
        Token temp = l->getNextToken();
        if(l->peekNextToken().token == CIRCLEOP_BRACKET){
            l->getNextToken();
            fnCl = new FnCall(temp, l);
        }
        else{
            t =temp;
        }
    }
    else if(l->peekNextToken().token == CIRCLEOP_BRACKET){
        subExpr = new SubExpression(l);
    }
    else if(l->peekNextToken().token == SUB_ADDOP || l->peekNextToken().token == NOT_UNARY){
        un = new Unary(l);
    }
    else{
        std::cerr << "Incorrect expression use" << "\n";
        exit(EXIT_FAILURE);
    }
}