
%:include <stdio.h>

#define PRINT_SQUARE(X) printf(#X "*" #X " = %d \n", X*X)


int main()
{
    int ch;
    unsigned long int count = 0;

    FILE *fp = fopen("./dns.c", "r");

    while ( (ch = getc(fp)) != EOF )
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("%ld\n", count);

    PRINT_SQUARE(8);
    return 0;
}


