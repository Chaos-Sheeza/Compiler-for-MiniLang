#include "MainHeader.h"

FormalParams::FormalParams(Lexer* l){
    first = new FormalParam(l);
    while(l->peekNextToken().token != CIRCLECL_BRACKET){
        if(l->getNextToken().token != COMMA_PUNCT){
            std::cerr << "Missing ," << "\n";
        }
        set.push_back(new FormalParam(l));
    }
}