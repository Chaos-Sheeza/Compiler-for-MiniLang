#include <iostream>
#include "ClassLib/Lexer.h"
#include "ClassLib/Parser.h"

int main( int argc, const char* argv[])
{
    std::string fileName = "../TestCode.txt";
    Lexer* l = new Lexer(fileName);
    l->debugPrint();
    Parser* p = new Parser(l);
    Visitor* v;
    p->prog->accept(v);
    return 0;
}
