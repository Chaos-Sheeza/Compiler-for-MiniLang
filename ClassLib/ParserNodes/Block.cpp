#include "MainHeader.h"

Block::Block(Lexer* l){
    if(l->getNextToken().token != CURLYOP_BRACKET){
        std::cerr << "Incorrect start to block" << "\n";
        exit(EXIT_FAILURE);
    }
    st = new Statement(l);
    if(l->getNextToken().token != CURLYCL_BRACKET){
        std::cerr << "Incorrect end to block" << "\n";
        exit(EXIT_FAILURE);
    }
}