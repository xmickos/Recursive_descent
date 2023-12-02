#include "RD_header.hpp"

const char* s = NULL;
int p = 0;

int GetG(char* str){
    s = str;
    p = 0;
    int val = GetE();
    syn_assert(s[p] == '\0');

    return val;
}

int GetE(){
    int val = GetN();
    while(s[p] == '+' || s[p] == '-'){
        char op = s[p];
        p++;
        int val2 = GetN();
        switch(op)
        {
        case '+':
            val += val2;
            break;
        case '-':
            val -= val2;
            break;
        default:
            syntax_error();
        }

        return val;
    }
}

// int GetT(){}

int GetN(){

    int val = 0;
    int old_p = p;

    while('0' <= s[p] && s[p] <= '9')
    {
        val = 10*val + s[p] - '0';
        p++;
    }
    syn_assert(p > old_p);
    return val;
}

void syntax_error(){
    printf("Syntax error.\nExiting...\n");
    exit(-1);
}

void syn_assert(bool condition){

    if(!condition){
        printf("Syntax error.\nExiting...\n");
        exit(-1);
    }
}


