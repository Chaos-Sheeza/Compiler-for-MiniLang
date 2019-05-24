#include "Lexer.h"

Lexer::Lexer(string fileName){
        std::ifstream ifs(fileName);
        fileStr.assign( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        GenerateTokens();
}

void Lexer::debugPrint(){
    for (int i = 0; i < allTokens.size(); i++)
    {
        std::cout << allTokens[i].token << "\n";
    }
    
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
    else if(c == '{' || c == '}' || c == '(' || c == ')' || c == ';' || c == ',' || c == ':'){
        return 11;
    }
    else{
        return 0;
    }
}

Token Lexer::keywordHandling(string lexeme){
    int temp = 0;
    for (int i = 1; i < 16; i++)
    {
        if(lexeme == keywords[i]){
            temp = i;
            break;
        }
    }
    switch(temp){
        case 15:
            return Token(PRINT_DEC,lexeme,0);
            break;
        case 1:
            return Token(FLOAT_TYPE,lexeme,0);
            break;
        case 2:
            return Token(INT_TYPE,lexeme,0);
            break;
        case 3:
            return Token(BOOL_TYPE,lexeme,0);
            break;
        case 4:
            return Token(TRUE_BOOLLIT,lexeme,0);
            break;
        case 5:
            return Token(FALSE_BOOLLIT,lexeme,0);
            break;
        case 6:
            return Token(AND_MULTOP,lexeme,0);
            break;
        case 7:
            return Token(OR_ADDOP,lexeme,0);
            break;
        case 8:
            return Token(NOT_UNARY,lexeme,0);
            break;
        case 9:
            return Token(VAR_DEC,lexeme,0);
            break;
        case 10:
            return Token(FN_DEC,lexeme,0);
            break;
        case 11:
            return Token(RET_EXP,lexeme,0);
            break;
        case 12:
            return Token(IF_EXP,lexeme,0);
            break;
        case 13:
            return Token(ELSE_EXP,lexeme,0);
            break;
        case 14:
            return Token(FOR_STATE,lexeme,0);
            break;
        default:
            return Token(VARNAME_DEC,lexeme,0);
            break;
    }
}

Token Lexer::opHandling(string lexeme){
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        if(lexeme == ops[i]){
            temp = i;
            break;
        }
    }
    switch (temp)
    {
    case 0:
        return Token(ADD_ADDOP,lexeme,1);
        break;
    case 1:
        return Token(SUB_ADDOP,lexeme,0);
        break;
    case 2:
        return Token(MULT_MULTOP,lexeme,2);
        break;
    default:
        return Token();
        break;
    }
}

Token Lexer::relOpHandling(string lexeme){
    int temp = 0;
    for (int i = 0; i < 6; i++)
    {
        if(lexeme == relOps[i]){
            temp = i;
            break;
        }
    }

    switch (temp)
    {
    case 0:
        return Token(EQ_DEC,lexeme,0);
        break;
    case 1:
        return Token(GREAT_RELOP,lexeme,0);
        break;
    case 2:
        return Token(SMALL_RELOP,lexeme,0);
        break;
    case 3:
        return Token(EQ_RELOP,lexeme,0);
        break;
    case 4:
        return Token(GREATEQ_RELOP,lexeme,0);
        break;
    case 5:
        return Token(SMALLEQ_RELOP,lexeme,0);
        break;
    default:
        return Token();
        break;
    }
}

Token Lexer::punctHandling(string lexeme){
    int temp = 0;
    for (int i = 0; i < 7; i++)
    {
        if(lexeme == punct[i]){
            temp = i;
            break;
        }
    }

    switch (temp)
    {
    case 0:
        return Token(CIRCLEOP_BRACKET,lexeme,0);
        break;
    case 1:
        return Token(CIRCLECL_BRACKET,lexeme,0);
        break;
    case 2:
        return Token(CURLYOP_BRACKET,lexeme,0);
        break;
    case 3:
        return Token(CURLYCL_BRACKET,lexeme,0);
        break;
    case 4:
        return Token(SEMICOL_PUNCT,lexeme,0);
        break;
    case 5:
        return Token(COMMA_PUNCT,lexeme,0);
        break;
    case 6:
        return Token(COL_PUNCT,lexeme,0);
        break;
    default:
        return Token();
        break;
    }
}

void Lexer::states(string lexeme, int state){
    switch (state)
    {
    case 1:
        allTokens.push_back (keywordHandling(lexeme));
        break;
    case 2: case 15:
        allTokens.push_back (Token(NUMBER_DEC,lexeme,std::stof(lexeme)));
        break;
    case 3: case 17: case 11:
        std::cout << "Syntax error: incorrect use of \"" << lexeme << "\"\n";
        allTokens.push_back (Token(NONTOKEN,lexeme,0));
        break;
    case 4:
        allTokens.push_back (opHandling(lexeme));
        break;
    case 5:
        allTokens.push_back (Token(DIV_MULTOP,lexeme,4));
        break;
    case 6: case 7:
        std::cout << "Comments never closed";
        allTokens.push_back (Token(NONTOKEN,lexeme,0));
        break;
    case 8: case 9: case 10: case 18: case 16:
        break;
    case 12:
        allTokens.push_back (Token(NOTEQ_RELOP,lexeme,0));
        break;
    case 13: case 14:
        allTokens.push_back (relOpHandling(lexeme));
        break;
    case 19:
        allTokens.push_back (punctHandling(lexeme));
        break;
    
    default:
        allTokens.push_back(Token());
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
            states(lexeme,prevState);
            prevState = 0;
            lexeme = "";
        }
        else{
            prevState = dfaTable[row][prevState];
            lexeme += fileStr[i];
            i++;
        }
    }
    states(lexeme,prevState);
    prevState = 0;
    lexeme = "";
    allTokens.push_back(Token());
}

Token Lexer::getNextToken(){
    tokenCounter++;
    if (tokenCounter-1 < allTokens.size()){
        return allTokens[tokenCounter-1];
    }
    else
    {
        return Token();
    }   
}

Token Lexer::peekNextToken(){
    if (tokenCounter < allTokens.size()){
        return allTokens[tokenCounter];
    }
    else
    {
        return Token();
    } 
}
