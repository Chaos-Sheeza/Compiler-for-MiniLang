#include <string>
using std::string;

class Token{

private:
    /* data */

public:

    enum tokenType{
        FLOAT_TYPE = 1,
        INT_TYPE,
        BOOL_TYPE,
        TRUE_BOOLLIT,
        FALSE_BOOLLIT,
        MULT_MULTOP = 10,
        DIV_MULTOP,
        AND_MULTOP,
        ADD_ADDOP,
        SUB_ADDOP,
        OR_ADDOP,
        GREAT_RELOP,
        SMALL_RELOP,
        EQ_RELOP,
        NOTEQ_RELOP,
        SMALLEQ_RELOP,
        GREATEQ_RELOP,
        NOT_UNARY,
        VAR_DEC = 30,
        VARNAME_DEC,
        COL_DEC,
        SEMCOL_DEC,
        EQ_DEC,
        FN_DEC,
        RET_EXP,
        IF_EXP,
        ELSE_EXP,
        FOR_STATE,
        CURLY_BRACKET,
        SQUARE_BRACKET,
        CIRCLE_BRACKET,
        NONTOKEN = 50
    };
    tokenType token;
    string lexeme;
    float value;  

    Token(tokenType type, string lexeme, float value){
        this->token = type;
        this->lexeme = lexeme;
        this->value = value;
    }

    ~Token();

};
