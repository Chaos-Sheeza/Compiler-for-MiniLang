#include <iostream>
#include "ClassLib/Lexer.h"
#include "ClassLib/Parser.h"

int main( int argc, const char* argv[])
{
    std::string fileName = "../Test.txt";
    Lexer l = Lexer(fileName);
    l.debugPrint();
    Parser p = Parser(l);
    return 0;
}
