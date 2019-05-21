#include "../Lexer.h"
#include "FnCall.h"
#include "SubExpression.h"
#include "Unary.h"

class Factor
{
private:
    /* data */
public:
    Token t;
    FnCall* fnCl;
    SubExpression* subExpr;
    Unary* un;
    
    Factor(Lexer);
    ~Factor();
};
