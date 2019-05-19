#include "../Lexer.h"
#include "Expression.h"

class VarDec
{
public:
    Token iden;
    Token type;
    Expression* e;
    VarDec(Lexer);
    ~VarDec();
};
