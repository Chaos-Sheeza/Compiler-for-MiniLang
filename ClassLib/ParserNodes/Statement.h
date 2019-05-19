#include "../Lexer.h"
#include "VarDec.h"
#include "Assignment.h"
#include "PrintState.h"
#include "VarDec.h"
#include "IfState.h"
#include "ForState.h"
#include "ReturnState.h"
#include "FnDec.h"
#include "Block.h"


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
