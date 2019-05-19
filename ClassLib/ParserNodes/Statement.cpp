#include "Statement.h"

Statement::Statement(Lexer l){
    Token t = l.getNextToken();
    switch (t.token)
    {
    case VAR_DEC:
        vrs = new VarDec(l);
        if (l.getNextToken().token != SEMICOL_PUNCT)
        {
            std::cerr << "Syntax error: forgot end of line token" << "\n";
            exit(EXIT_FAILURE);
        }
        break;
    case IF_EXP:
        ifs = new IfState();
        break;
    case FOR_STATE:
        fors = new ForState();
        break;
    case RET_EXP:
        ret = new ReturnState();
        break;
    case FN_DEC:
        fn = new FnDec();
        break;
    case CURLYOP_BRACKET:
        bl = new Block();
        break;
    default:
        std::cout << "Syntax error in " << t.lexeme << "\n";
        break;
    }
}
