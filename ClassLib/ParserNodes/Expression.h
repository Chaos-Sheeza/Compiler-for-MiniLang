#include "SimpleExpr.h"
#include "../Lexer.h"
using std::pair;

class Expression
{
public:
    SimpleExpr* node1;
    vector< pair <Token, SimpleExpr*>> node2Set;
    Expression(Lexer);
    ~Expression();
};
