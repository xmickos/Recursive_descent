#include "RD_header.hpp"


int p = 0;
const char* s = NULL;


/*
I   итерация: односимвольные числа
    G ::= N'\0'
    N ::= ['0'-'9']         // пустые строчки разрешены ? Не помню

II  итерация: многосимвольные числа
    G ::= N'\0'
    N :: ['0'-'9']+

III итерация: сложение и вычитание
    G ::= E'\0'
    E ::= N{[+-]N}*
    N ::= ['0'-'9']+

IV  итерация: умножение и деление с приоритетами, без скобок
    G ::= E'\0'     -- grammatic
    E ::= T{[+-]T}* -- expression
    T ::= N{[*\]N}* -- term
    N ::= ['0'-'9'] -- numeral


V  итерация: умножение и деление со скобками
    G ::= E'\0'
    E ::= T{[+-]T}*
    T ::= P{[*\]P}*
    P ::= '('E')' | N
    N ::= ['0'-'9']+

    (2+5)*(2-5)'\0'
*/


int GetG(const char* str, FILE* logfile){
    VERIFY_LOGFILE(logfile);

    s = str;
    p = 0;

    DEBUG_CALL(GetE, logfile);
    int val = GetE(logfile);

    if(s[p] == '\0'){
        return val;
    }

    DEBUG_CALL(syntax_error, logfile);
    return syntax_error(logfile);
}

int GetE(FILE* logfile){
    DEBUG_ECHO(logfile);

    DEBUG_CALL(GetT, logfile);
    int val = GetT(logfile), val2 = 0, op = 0;

    while(s[p] == '+' || s[p] == '-'){
        DEBUG_ECHO(logfile);
        op = s[p];
        p++;
        DEBUG_CALL(GetT, logfile);
        val2 = GetT(logfile);
        switch(op){
            case '+':
                val = val + val2;
                break;
            case '-':
                val = val - val2;
                break;
            default:
                DEBUG_CALL(syntax_error, logfile);
                syntax_error(logfile);
        }
    }

    return val;
}

int GetT(FILE* logfile){
    DEBUG_ECHO(logfile);

    DEBUG_CALL(GetP, logfile);
    int val = GetP(logfile), val2 = 0, op = 0;

    while(s[p] == '*' || s[p] == '/'){
        DEBUG_ECHO(logfile);
        op = s[p];
        p++;
        DEBUG_CALL(GetP, logfile);
        val2 = GetP(logfile);
        switch(op){
            case '*':
                val = val * val2;
                break;
            case '/':
                val = val / val2;
                break;
            default:
                DEBUG_CALL(syntax_error, logfile);
                syntax_error(logfile);
        }
    }

    return val;
}

int GetP(FILE* logfile){
    DEBUG_ECHO(logfile);

    int val = 0;

    if(s[p] == '('){
        p++;
        val = GetE(logfile);
    }else{
        return GetN(logfile);
    }
    if(s[p] == ')'){
        p++;
        return val;
    }
}

int GetN(FILE* logfile){
    DEBUG_ECHO(logfile);

    int val = 0;

    if(s[p] - '0' > 9 || s[p] - '0' < 0){
        syntax_error(logfile);                  //Хотя бы одна цифра в начале должна быть,
    }                                           //иначе syntax_error; Тогда пустые строки запрещены

    while(s[p] - '0' <= 9 && s[p] - '0' >= 0){
        val = 10*val + s[p] - '0';
        p++;
    }

    return val;
}

int syntax_error(FILE* logfile){
    VERIFY_LOGFILE(logfile);

    printf("\033[1;31mSyntax error\033[0m at p = %d: %s\n", p, s + p);
    fprintf(logfile, "Syntax error at p = %d: s = %s\n", p, s + p);

    exit(-1);       // ?..

    return 0;
}
