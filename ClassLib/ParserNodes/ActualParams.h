#include "../Lexer.h"
#include "Expression.h"

class ActualParams
{
public:
    Expression* expr;
    vector<pair <Token, Expression*>> exprSet;
    ActualParams(Lexer);
    ~ActualParams();
};
