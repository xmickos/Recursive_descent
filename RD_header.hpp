#include <stdio.h>
#include <stdlib.h>
// Первый удачный запуск -- 23:12, старт счёта в 22:45-22:47

int GetN();

int GetG(char* str);

void syntax_error();

void syn_assert(bool condition);

int GetE();

//
// G_3 ::= E'\0'
// T ::= N{[*/}N*
// E ::= T{[+-]T}*
// N ::= ['0'-'9']
//
