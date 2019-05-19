#include "Statement.h"
#include "../Lexer.h"

class Program
{
public:
    vector<Statement> statements;
    Program(Lexer);
    ~Program();
};
