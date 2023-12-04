#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_SIZE 128

#define VERIFY_LOGFILE(logfile) do{ if(logfile == nullptr){ printf("\033[1;31mWe've lost logfile!\033[0m\n "); return -1;}} while(0)

#define DEBUG_ECHO(logfile) do{ fprintf(logfile, "I am %s, p = %d, next symbols is %c\n", __FUNCTION__, p, s[p]); }while(0)
#define DEBUG_CALL(next_func, logfile) do{ fprintf(logfile, "I am %s, calling " #next_func "\n", __FUNCTION__);}while(0)

struct Lexema{
    int type = 0;
    int val = 0;
    char name[128] = {};
};

int syntax_error(FILE* logfile);

int GetG(const char* str, FILE* logfile);

int GetE(FILE* logfile);

int GetT(FILE* logfile);

int GetP(FILE* logfile);

int GetN(FILE* logfile);

