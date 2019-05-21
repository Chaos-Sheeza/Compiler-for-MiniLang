#include "../Lexer.h"

class Program
{
public:
    vector<Statement> statements;
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

    Statement(Lexer);
    ~Statement();
};

class VarDec
{
public:
    Token iden;
    Token type;
    Expression* e;
    VarDec(Lexer);
    ~VarDec();
};

class Expression
{
public:
    SimpleExpr* node1;
    vector< pair <Token, SimpleExpr*>> node2Set;
    Expression(Lexer);
    ~Expression();
};

class SimpleExpr
{
public:
    Term* node1;
    vector<pair <Token, Term*>> node2Set;
    SimpleExpr(Lexer);
    ~SimpleExpr();
};

class Term
{
public:
    Factor* node1;
    vector<pair <Token, Factor*>> node2Set;
    Term(Lexer);
    ~Term();
};

class Factor
{
public:
    Token t;
    FnCall* fnCl;
    SubExpression* subExpr;
    Unary* un;
    
    Factor(Lexer);
    ~Factor();
};

class FnCall
{
public:
    Token t;
    ActualParams* ap;
    FnCall(Token, Lexer);
    ~FnCall();
};

class SubExpression
{
public:
    SubExpression(Lexer);
    ~SubExpression();
};

class ActualParams
{
public:
    Expression* expr;
    vector<pair <Token, Expression*>> exprSet;
    ActualParams(Lexer);
    ~ActualParams();
};

class Unary
{
public:
    Unary(Lexer);
    ~Unary();
};

class IfState
{
public:
    IfState();
    ~IfState();
};

class ForState
{
public:
    ForState();
    ~ForState();
};

class ReturnState
{
public:
    ReturnState();
    ~ReturnState();
};

class FnDec
{
public:
    FnDec();
    ~FnDec();
};

class Block
{
public:
    Block();
    ~Block();
};

