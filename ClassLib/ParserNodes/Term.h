#include "../Lexer.h"
#include "Factor.h"

class Term
{
public:
    Factor* node1;
    vector<pair <Token, Factor*>> node2Set;
    Term(Lexer);
    ~Term();
};
