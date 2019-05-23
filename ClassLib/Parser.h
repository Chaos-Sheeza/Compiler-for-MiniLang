#include "Token.h"
#include "Lexer.h"
#include "ParserNodes/MainHeader.h"


#ifndef MAIN_PARSER_H
#define MAIN_PARSER_H

class Parser
{
public:
    Parser(Lexer);
    Program* prog = nullptr;
    //~Parser();
};

#endif