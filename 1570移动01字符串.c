
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int len = n/16 + (n%16 > 0);
    unsigned short int num[len];
    for (int i=0; i<len; i++)
    {
        scanf("%x", &num[i]);
        printf("%x\n", num[i]);
    }

    char str[len*16 + 1];

    for (int i=0; i<len; i++)
    {
        sprintf(&str[i*16], "%b" , num[i]);
    }

    printf("%b\n", num[1]);

    puts(str);

    
    return 0;
}






