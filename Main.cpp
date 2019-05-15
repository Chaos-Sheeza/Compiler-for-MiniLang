#include <iostream>
#include "ClassLib/Lexer.h"

int main( int argc, const char* argv[] )
{
    std::string fileName = "../Test.txt";
    Lexer l = Lexer(fileName);
    //l.debugPrint();
    l.GenerateTokens();
    
    return 0;
}
