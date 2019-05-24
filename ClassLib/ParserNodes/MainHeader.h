#include "../Lexer.h"


#ifndef MAIN_AST_H
#define MAIN_AST_H

class ActualParams;
class FnCall;
class SubExpression;
class Unary;
class Factor;
class Term;
class SimpleExpr;
class Expression;
class VarDec;
class Block;
class IfState;
class ReturnState;
class Assignment;
class ForState;
class PrintState;
class FormalParam;
class FormalParams;
class FnDec;
class Statement;
class Program;

class Visitor
{
public:
    int tabCounter = 0;
    Visitor();

    void visit(ActualParams*);
    void visit(FnCall*);
    void visit(SubExpression*);
    void visit(Unary*);
    void visit(Factor*);
    void visit(Term*);
    void visit(SimpleExpr*);
    void visit(Expression*);
    void visit(VarDec*);
    void visit(Block*);
    void visit(IfState*);
    void visit(ReturnState*);
    void visit(Assignment*);
    void visit(ForState*);
    void visit(PrintState*);
    void visit(FormalParam*);
    void visit(FormalParams*);
    void visit(FnDec*);
    void visit(Statement*);
    void visit(Program*);

    ~Visitor();
};

class ActualParams
{
public:
    Expression* expr = nullptr;
    vector<Expression*> exprSet;
    ActualParams(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~ActualParams();
};

class FnCall
{
public:
    Token t;
    ActualParams* ap = nullptr;
    FnCall(Token, Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~FnCall();
};

class SubExpression
{
public:
    Expression* expr = nullptr;
    SubExpression(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~SubExpression();
};

class Unary
{
public:
    Token t;
    Expression* expr = nullptr;
    Unary(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~Unary();
};

class Factor
{
public:
    Token t;
    FnCall* fnCl = nullptr;
    SubExpression* subExpr = nullptr;
    Unary* un;
    
    Factor(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~Factor();
};

class Term
{
public:
    Factor* node1 = nullptr;
    vector<pair <Token, Factor*>> node2Set;
    Term(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~Term();
};

class SimpleExpr
{
public:
    Term* node1 = nullptr;
    vector<pair <Token, Term*>> node2Set;
    SimpleExpr(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~SimpleExpr();
};

class Expression
{
public:
    SimpleExpr* node1 = nullptr;
    vector< pair <Token, SimpleExpr*>> node2Set;
    Expression(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~Expression();
};

class VarDec
{
public:
    Token iden;
    Token type;
    Expression* e = nullptr;
    VarDec(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~VarDec();
};

class Statement;

class Block
{
public:
    Statement* st = nullptr;
    Block(Lexer* l);
    void accept(Visitor* v){ v->visit(this); };
    ~Block();
};

class IfState
{
public:
    Expression* expr = nullptr;
    Block* ifBl = nullptr;
    Block* elseBl = nullptr;
    IfState(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~IfState();
};

class ReturnState
{
public:
    Expression* expr = nullptr;
    ReturnState(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~ReturnState();
};

class Assignment
{
public:
    Token t;
    Expression* exp = nullptr;
    Assignment(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~Assignment();
};

class ForState
{
public:
    VarDec* vr = nullptr;
    Expression* ex = nullptr;
    Assignment* at = nullptr;
    Block* bl = nullptr;
    ForState(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~ForState();
};

class PrintState
{
public:
    Expression* expr = nullptr;
    PrintState(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~PrintState();
};

class FormalParam
{
public:
    Token id;
    Token type;
    FormalParam(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~FormalParam();
};

class FormalParams
{
public:
    FormalParam* first;
    vector<FormalParam*> set;
    FormalParams(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~FormalParams();
};

class FnDec
{
public:
    Token id;
    FormalParams* param;
    Token type;
    Block* bl;
    FnDec(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~FnDec();
};

class Statement
{
public:
    VarDec* vrs = nullptr;
    IfState* ifs = nullptr;
    ForState* fors = nullptr;
    ReturnState* ret = nullptr;
    FnDec* fn = nullptr;
    Block* bl = nullptr;
    PrintState* pr = nullptr;
    
    Statement(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~Statement();
};

class Program
{
public:
    vector<Statement*> statements;
    Program(Lexer*);
    void accept(Visitor* v){ v->visit(this); };
    ~Program();
};


#endif
