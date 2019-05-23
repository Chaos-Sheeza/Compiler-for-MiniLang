#include "Token.h"
#include "Lexer.h"
#include "ParserNodes/MainHeader.h"


#ifndef MAIN_PARSER_H
#define MAIN_PARSER_H

class Parser
{
public:
    Program* prog = nullptr;
    Parser(Lexer);
    ~Parser();
};

#endif