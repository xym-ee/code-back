#include <stdio.h>

#define XNAME(n) x ## n

#define PRINT_XN(n) printf("x" #n " = %d\n", n);

int main()
{
    int XNAME(1) = 1;
    int XNAME(2) = 2;

    PRINT_XN(1);
    PRINT_XN(2);
}


