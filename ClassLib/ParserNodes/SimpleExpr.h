#include "../Lexer.h"
#include "Term.h"

class SimpleExpr
{
public:
    Term* node1;
    vector<std::pair <Token, Term*>> node2Set;
    SimpleExpr(Lexer);
    ~SimpleExpr();
};
