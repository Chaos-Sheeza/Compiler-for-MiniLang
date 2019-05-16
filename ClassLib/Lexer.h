#include <string>
#include <fstream>
#include <iostream>
#include "Token.h"
#include <ctype.h>
#include <vector>
using std::vector;
using std::string;

#ifndef MAIN_LEXER_H
#define MAIN_LEXER_H

class Lexer{
    private:

    string fileStr = "";
    int dfaTable[12][20] = {
        //                  00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19
        /*ignorables*/  {   16, -1, -1, -1, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, -1, 16, -1, -1, -1},
        /*alph*/        {    1,  1, -1, -1, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*num*/         {    2,  1,  2, 15, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, 15, -1, -1, -1, -1},
        /*.*/           {   17, -1,  3, -1, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*+,-*/         {    4, -1, -1, -1, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /* * */         {    4, -1, -1, -1, -1,  6,  7,  6, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /* / */         {    5, -1, -1, -1, -1,  9,  6,  8, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*\n*/          {   18, -1, -1, -1, -1, -1,  6,  6, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*!*/           {   11, -1, -1, -1, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*=*/           {   13, -1, -1, -1, -1, -1,  6,  6, -1,  9, -1, 12, -1, 14, -1, -1, -1, -1, -1, -1},
        /*>,<*/         {   13, -1, -1, -1, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        /*punct*/       {   19, -1, -1, -1, -1, -1,  6,  6, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
        // -1 is the default state. States 9,7,6,3 are non-accepted states (generate non-tokens).
    };
    string keywords[15] = {"","float","int","bool","true","false","and","or","not","var","fn","return","if","else","for"};
    string ops[3] = {"+","-","*"};
    string relOps[6] = {"=",">","<","==",">=","<="};
    string punct[6] = {"(",")","{","}",";",","};

    int getRow(char);

    void states(string, int);

    Token keywordHandling(string);

    Token opHandling(string);

    Token relOpHandling(string);

    Token punctHandling(string);

    public:

    vector<Token> allTokens;

    Lexer(string);

    void GenerateTokens();

    void debugPrint();

    //~Lexer();
};

#endif //MAIN_LEXER_H
