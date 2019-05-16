#include <string>
using std::string;

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
    NUMBER_DEC,
    COL_DEC,
    SEMCOL_DEC,
    EQ_DEC,
    FN_DEC,
    RET_EXP,
    IF_EXP,
    ELSE_EXP,
    FOR_STATE,
    CURLYOP_BRACKET,
    CURLYCL_BRACKET,
    CIRCLEOP_BRACKET,
    CIRCLECL_BRACKET,
    SEMICOL_PUNCT,
    COMMA_PUNCT,
    NONTOKEN = 50
};

class Token{

public:
  
    tokenType token;
    string lexeme;
    float value;

    Token(){
        this->token = NONTOKEN;
        this->lexeme = "";
        this->value = 0;
    }  

    Token(tokenType type, string lexeme, float value){
        this->token = type;
        this->lexeme = lexeme;
        this->value = value;
    }

    //~Token();

};
