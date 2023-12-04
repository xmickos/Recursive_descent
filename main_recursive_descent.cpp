#include "RD_header.hpp"

int main(){

    FILE* logfile = fopen("logfile.txt", "w");

    const char input_str[DEFAULT_SIZE] = "2";

    int ans = GetG(input_str, logfile);

    printf("\033[1;32mAnswer\033[0m: %d\n", ans);

    fclose(logfile);

    return 0;
}
