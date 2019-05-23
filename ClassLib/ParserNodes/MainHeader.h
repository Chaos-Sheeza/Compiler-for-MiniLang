#include "../Lexer.h"

class Program
{
public:
    vector<Statement*> statements;
    Program(Lexer);
    ~Program();
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

class VarDec
{
public:
    Token iden;
    Token type;
    Expression* e = nullptr;
    VarDec(Lexer);
    ~VarDec();
};

class Expression
{
public:
    SimpleExpr* node1 = nullptr;
    vector< pair <Token, SimpleExpr*>> node2Set;
    Expression(Lexer);
    ~Expression();
};

class SimpleExpr
{
public:
    Term* node1 = nullptr;
    vector<pair <Token, Term*>> node2Set;
    SimpleExpr(Lexer);
    ~SimpleExpr();
};

class Term
{
public:
    Factor* node1 = nullptr;
    vector<pair <Token, Factor*>> node2Set;
    Term(Lexer);
    ~Term();
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

class ActualParams
{
public:
    Expression* expr = nullptr;
    vector<Expression*> exprSet;
    ActualParams(Lexer);
    ~ActualParams();
};

class Unary
{
public:
    Token t;
    Expression* expr = nullptr;
    Unary(Lexer);
    ~Unary();
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

class ReturnState
{
public:
    Expression* expr = nullptr;
    ReturnState(Lexer);
    ~ReturnState();
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

class Block
{
public:
    Statement* st = nullptr;
    Block(Lexer l);
    ~Block();
};

class PrintState
{
public:
    Expression* expr = nullptr;
    PrintState(Lexer);
    ~PrintState();
};

class Assignment
{
public:
    Token t;
    Expression* exp = nullptr;
    Assignment(Lexer);
    ~Assignment();
};

class FormalParams
{
public:
    FormalParam* first;
    vector<FormalParam*> set;
    FormalParams(Lexer);
    ~FormalParams();
};

class FormalParam
{
public:
    Token id;
    Token type;
    FormalParam(Lexer);
    ~FormalParam();
};
