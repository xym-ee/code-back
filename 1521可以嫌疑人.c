
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int num;
    int n = 0;
    int men[100001];
    memset(men, 0, sizeof(men));

    while ( scanf("%d,", &num) != EOF)
    {
        men[num] ++;
        n++;
    }
    int index = 0;
    int max = 0;

    for (int i=0; i<100001; i++)
    {
        if (max < men[i])
        {
            max = men[i];
            index = i;
        }
    }

    if (max > n/2 + !(n%2))
        printf("%d\n", index);
    else
        printf("0\n");
    return 0;
}







