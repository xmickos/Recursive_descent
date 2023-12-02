#include "RD_header.hpp"

int main(){

    char str[128] = "57";
    str[2] = '\0';

    int x = GetG(str);
    printf("%d", x);

    return 0;
}
