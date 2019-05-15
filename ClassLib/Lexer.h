#include <string>
#include <fstream>
#include <iostream>
#include "Token.h"
#include <ctype.h>
using std::string;

#ifndef MAIN_LEXER_H
#define MAIN_LEXER_H

class Lexer{
    private:

    string fileStr;
    int dfaTable[11][19] = {
        //                  00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18
        /*ignorables*/  {   16, -1, -1, -1, -1, -1, -1,  7, -1,  9, -1, -1, -1, -1, -1, -1, 16, -1, -1},
        /*alph*/        {    1,  1, -1, -1, -1, -1, -1,  7, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*num*/         {    2,  1,  2, 15, -1, -1, -1,  7, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*.*/           {   17, -1,  3, -1, -1, -1, -1,  7, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*+,-*/         {    4, -1, -1, -1, -1, -1, -1,  7, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /* * */         {    4, -1, -1, -1, -1,  6,  7,  7, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /* / */         {    5, -1, -1, -1, -1,  9, -1,  8, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*\n*/          {   18, -1, -1, -1, -1, -1, -1,  7, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*!*/           {   11, -1, -1, -1, -1, -1, -1,  7, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*=*/           {   13, -1, -1, -1, -1, -1, -1,  7, -1,  9, -1, 12, -1, 14, -1, -1, -1, -1, -1},
        /*>,<*/         {   13, -1, -1, -1, -1, -1, -1,  7, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1}
        // -1 is the default state. States 9,7,6,3 are non-accepted states (generate non-tokens).
    };

    int getRow(char);

    void states(string, int);

    Token state1(string);

    public:

    //Token allTokens[];

    Lexer(string fileName);

    void GenerateTokens();

    void debugPrint();

};

#endif //MAIN_LEXER_H
