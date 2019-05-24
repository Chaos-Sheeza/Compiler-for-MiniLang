#include "Parser.h"

Parser::Parser(Lexer* l){
        prog = new Program(l);
}