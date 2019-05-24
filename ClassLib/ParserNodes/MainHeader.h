#include "../Lexer.h"


#ifndef MAIN_AST_H
#define MAIN_AST_H

class Expression;
class FnDec;
class Visitor;

class ActualParams
{
public:
    Expression* expr = nullptr;
    vector<Expression*> exprSet;
    ActualParams(Lexer);
    ~ActualParams();
};

class FnCall
{
public:
    Token t;
    ActualParams* ap = nullptr;
    FnCall(Token, Lexer);
    ~FnCall();
};

class SubExpression
{
public:
    Expression* expr = nullptr;
    SubExpression(Lexer);
    ~SubExpression();
};

class Unary
{
public:
    Token t;
    Expression* expr = nullptr;
    Unary(Lexer);
    ~Unary();
};

class Factor
{
public:
    Token t;
    FnCall* fnCl = nullptr;
    SubExpression* subExpr = nullptr;
    Unary* un;
    
    Factor(Lexer);
    ~Factor();
};

class Term
{
public:
    Factor* node1 = nullptr;
    vector<pair <Token, Factor*>> node2Set;
    Term(Lexer);
    ~Term();
};

class SimpleExpr
{
public:
    Term* node1 = nullptr;
    vector<pair <Token, Term*>> node2Set;
    SimpleExpr(Lexer);
    ~SimpleExpr();
};

class Expression
{
public:
    SimpleExpr* node1 = nullptr;
    vector< pair <Token, SimpleExpr*>> node2Set;
    Expression(Lexer);
    ~Expression();
};

class VarDec
{
public:
    Token iden;
    Token type;
    Expression* e = nullptr;
    VarDec(Lexer);
    ~VarDec();
};

class Statement;

class Block
{
public:
    Statement* st = nullptr;
    Block(Lexer l);
    ~Block();
};

class IfState
{
public:
    Expression* expr = nullptr;
    Block* ifBl = nullptr;
    Block* elseBl = nullptr;
    IfState(Lexer);
    ~IfState();
};

class ReturnState
{
public:
    Expression* expr = nullptr;
    ReturnState(Lexer);
    ~ReturnState();
};

class Assignment
{
public:
    Token t;
    Expression* exp = nullptr;
    Assignment(Lexer);
    ~Assignment();
};

class ForState
{
public:
    VarDec* vr = nullptr;
    Expression* ex = nullptr;
    Assignment* at = nullptr;
    Block* bl = nullptr;
    ForState(Lexer);
    ~ForState();
};

class PrintState
{
public:
    Expression* expr = nullptr;
    PrintState(Lexer);
    ~PrintState();
};

class FormalParam
{
public:
    Token id;
    Token type;
    FormalParam(Lexer);
    ~FormalParam();
};

class FormalParams
{
public:
    FormalParam* first;
    vector<FormalParam*> set;
    FormalParams(Lexer);
    ~FormalParams();
};

class FnDec
{
public:
    Token id;
    FormalParams* param;
    Token type;
    Block* bl;
    FnDec(Lexer);
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
    
    Statement(Lexer);
    ~Statement();
};

class Program
{
public:
    vector<Statement*> statements;
    Program(Lexer);

    void accept(Visitor);

    ~Program();
};

class Visitor
{
public:
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

#endif