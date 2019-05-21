#include "../Lexer.h"
#include "ActualParams.h"

class FnCall
{
public:
    Token t;
    ActualParams* ap;
    FnCall(Token, Lexer);
    ~FnCall();
};
