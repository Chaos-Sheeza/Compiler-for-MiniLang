#include <iostream>
#include "ClassLib/Lexer.h"

int main( int argc, const char* argv[] )
{
    std::string fileName = "../TestCode.txt";
    Lexer l = Lexer(fileName);
    //l.debugPrint();
    return 0;
}
