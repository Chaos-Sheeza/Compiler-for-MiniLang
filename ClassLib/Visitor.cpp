#include "ParserNodes/MainHeader.h"
using std::cout;

void Visitor::visit(Assignment* a){
    for(int j=0;j<tabCounter;j++){
        cout << "\t";
    }
    cout << "<Assignment>\n";
    tabCounter++;
    cout << "\t<id>" << a->t.lexeme << "</id>\n";
    tabCounter++;
    a->exp->accept(this);
    tabCounter--;
    for(int j=0;j<tabCounter;j++){
        cout << "\t";
    }
    cout << "</Assignment>\n";
}

void Visitor::visit(FnCall* f){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<FnCall>\n";

    tabCounter++;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<id>" << f->t.lexeme << "</id>\n";

    tabCounter++;
    if(f->ap != nullptr){
        f->ap->accept(this);
    }

    tabCounter -= 2;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</FnCall>\n";
}

void Visitor::visit(SubExpression* sb){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<SubExpression>\n";

    tabCounter++;
    sb->expr->accept(this);

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</SubExpression>\n";
}

void Visitor::visit(Unary* un){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<UnaryOp>\n";

    tabCounter++;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<op>" << un->t.lexeme << "</op>\n";

    tabCounter++;
    un->expr->accept(this);
    
    tabCounter -= 2;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</UnaryOp>\n";
}

void Visitor::visit(Factor* f){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<Factor>\n";

    tabCounter++;
    if(f->fnCl != nullptr){
        f->fnCl->accept(this);
    }
    else if(f->subExpr != nullptr){
        f->subExpr->accept(this);
    }
    else if(f->un != nullptr){
        f->un->accept(this);
    }
    else if(f->t.token != NONTOKEN){
        for(int j=0;j<tabCounter;j++){ cout << "\t"; }
        cout << "<value>" << f->t.lexeme << "</value>\n";
    }    

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</Factor>\n";
}

void Visitor::visit(Term* tm){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<Term>\n";

    tabCounter++;
    tm->node1->accept(this);
    int i = 0;
    while(i < tm->node2Set.size()){
        cout << "<MultOp>" << tm->node2Set[i].first.lexeme << "</MultOp>\n";
        tm->node2Set[i].second->accept(this);
        i++;
    }
    
    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</Term>\n";
}

void Visitor::visit(SimpleExpr* sp){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<SimpleExpression>\n";

    tabCounter++;
    sp->node1->accept(this);
    int i = 0;
    while(i < sp->node2Set.size()){
        cout << "<MultOp>" << sp->node2Set[i].first.lexeme << "</MultOp>\n";
        sp->node2Set[i].second->accept(this);
        i++;
    }
    
    tabCounter -= 2;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</SimpleExpression>\n";
}

void Visitor::visit(Expression* exp){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<Expression>\n";

    tabCounter++;
    exp->node1->accept(this);
    int i = 0;
    while(i < exp->node2Set.size()){
        cout << "<RelOp>" << exp->node2Set[i].first.lexeme << "</RelOp>\n";
        exp->node2Set[i].second->accept(this);
        i++;
    }
    
    tabCounter -= 2;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</Expression>\n";
}

void Visitor::visit(VarDec* vr){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<Var>\n";

    tabCounter++;
    cout << "<id>" << vr->iden.lexeme << "</id>\n";
    cout << "<type>" << vr->type.lexeme << "</type>\n";
    vr->e->accept(this);

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</Var>\n";
}

void Visitor::visit(Block* bl){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<Block>\n";

    tabCounter++;
    bl->st->accept(this);

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</Block>\n";
}

void Visitor::visit(IfState* ifs){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<IfState>\n";

    tabCounter++;
    ifs->expr->accept(this);
    tabCounter++;
    ifs->ifBl->accept(this);
    tabCounter--;
    if(ifs->elseBl != nullptr){
        ifs->elseBl->accept(this);
    }

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</IfState>\n";
}

void Visitor::visit(ReturnState* rs){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<Return>\n";

    tabCounter++;
    rs->expr->accept(this);

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</Return>\n";
}

void Visitor::visit(ForState* fs){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<ForStatement>\n";

    tabCounter++;
    if(fs->vr != nullptr){ fs->vr->accept(this); }
    fs->ex->accept(this);
    if(fs->at != nullptr){ fs->at->accept(this); }

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</ForStatement>\n";
}

void Visitor::visit(PrintState* ps){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<PrintState>\n";

    tabCounter++;
    ps->expr->accept(this);

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</PrintState>\n";
}

void Visitor::visit(FormalParam* fp){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<FormalParam>\n";

    tabCounter++;
    cout << "<id>" << fp->id.lexeme << "</id>\n";
    cout << "<type>" << fp->type.lexeme << "</type>\n";

    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</FormaleParam>\n";
}

void Visitor::visit(FormalParams* fps){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<FormalParams>\n";

    tabCounter++;
    fps->first->accept(this);
    int i = 0;
    while(i < fps->set.size()){
        fps->set[i]->accept(this);
        i++;
    }
    
    tabCounter --;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "</FormalParams>\n";
}

void Visitor::visit(FnDec* f){
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<FnDec>\n";

    tabCounter++;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    cout << "<id>" << f->id.lexeme << "</id>\n";

    tabCounter++;
    for(int j=0;j<tabCounter;j++){ cout << "\t"; }
    f->param->accept(this);
    cout << "<type>" << f->type.lexeme << "</type>\n";
    
    tabCounter++;
    f->bl->accept(this);

    tabCounter -= 3;
    for(int j=0;j<tabCounter;j++){
        cout << "\t";
    }
    cout << "</FnDec>\n";
}


void Visitor::visit(Program* p){
    cout << "<Program>\n";
    tabCounter++;
    int i = 0;
    while(p->statements[i]){
        p->statements[i]->accept(this);
        i++;
    }
    tabCounter--;
    cout << "</Program>\n";
}

void Visitor::visit(Statement* s){
    for(int j=0;j<tabCounter;j++){
        cout << "\t";
    }
    cout << "<Statement>\n";
    tabCounter++;
    if(s->vrs != nullptr){
        s->vrs->accept(this);
    }
    else if(s->ifs != nullptr){
        s->ifs->accept(this);
    }
    else if(s->fors != nullptr){
        s->fors->accept(this);
    }
    else if(s->ret != nullptr){
        s->ret->accept(this);
    }
    else if(s->fn != nullptr){
        s->fn->accept(this);
    }
    else if(s->bl != nullptr){
        s->bl->accept(this);
    }
    else if(s->pr != nullptr){
        s->pr->accept(this);
    }
    tabCounter--;
    for(int j=0;j<tabCounter;j++){
        cout << "\t";
    }
    cout << "</Statement>\n";
}
