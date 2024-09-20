
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100];
    int word_count = 0;
    int total_weight = 0;

    while ( scanf("%s", str) != EOF )
    {
        word_count++;
        total_weight += strlen(str);
    }
    
    double aver = ((double)total_weight)/((double)word_count);

    printf("%.2f\n", aver);
    
    return 0;
}




