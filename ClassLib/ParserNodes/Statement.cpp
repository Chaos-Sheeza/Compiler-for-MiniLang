#include "MainHeader.h"

Statement::Statement(Lexer* l){
    Token dick;
    switch (l->peekNextToken().token)
    {
    case VAR_DEC:
        l->getNextToken();
        vrs = new VarDec(l);
        dick = l->getNextToken();
        std::cout << dick.token << "\n";
        if (l->getNextToken().token != SEMICOL_PUNCT)
        {
            std::cerr << "Syntax error: forgot end of line token ;" << "\n";
            exit(EXIT_FAILURE);
        }
        break;
    case IF_EXP:
        l->getNextToken();
        ifs = new IfState(l);
        break;
    case FOR_STATE:
        l->getNextToken();
        fors = new ForState(l);
        break;
    case RET_EXP:
        ret = new ReturnState(l);
        if (l->getNextToken().token != SEMICOL_PUNCT)
        {
            std::cerr << "Syntax error: forgot end of line token ;" << "\n";
            exit(EXIT_FAILURE);
        }
        break;
    case FN_DEC:
        fn = new FnDec(l);
        break;
    case CURLYOP_BRACKET:
        bl = new Block(l);
        break;
    case PRINT_DEC:
        pr = new PrintState(l);
        l->getNextToken();
        break;
    default:
        std::cerr << "Syntax error in " << l->getNextToken().lexeme << "\n";
        exit(EXIT_FAILURE);
        break;
    }
}
