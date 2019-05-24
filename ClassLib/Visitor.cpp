#include "ParserNodes/MainHeader.h"

void Visitor::visit(Program* p){
    std::cout << "<Program>\n\t";
    int i = 0;
    while(p->statements[i]){
        p->statements[i]->accept(Visitor);
        i++;
    }
    std::cout << "</Program>\n";
}

