#include "Lexer.h"
using std::string;

Lexer::Lexer(string fileName){
        std::ifstream ifs(fileName);
        fileStr.assign( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
}

void Lexer::debugPrint(){
    std::cout << fileStr << "\n";
    return;
}

int Lexer::getRow(char c){
    if (isalpha(c)){
        return 1;
    }
    else if(isdigit(c)){
        return 2;
    }
    else if(c == '.'){
        return 3;
    }
    else if(c == '+' || c == '-'){
        return 4;
    }
    else if(c == '*'){
        return 5;
    }
    else if(c == '/'){
        return 6;
    }
    else if(c == '\n'){
        return 7;
    }
    else if(c == '!'){
        return 8;
    }
    else if(c == '='){
        return 9;
    }
    else if(c == '>' || c == '>'){
        return 10;
    }
    else{
        return 0;
    }
}

void Lexer::states(string lexeme, int state){
    switch (state)
    {
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    case 16:
        break;
    case 17:
        break;
    case 18:
        break;
    
    default:
        break;
    }
}



void Lexer::GenerateTokens(){
    int i = 0;
    int prevState = 0;
    int row = 0;
    string lexeme = "";
    while(fileStr[i]){
        row = getRow(fileStr[i]);
        if(dfaTable[row][prevState] == -1){
            std::cout << prevState << "\n";
            std::cout << lexeme << "\n";
            prevState = 0;
            lexeme = "";
        }
        else{
            prevState = dfaTable[row][prevState];
            lexeme += fileStr[i];
            i++;
        }
    }
}
