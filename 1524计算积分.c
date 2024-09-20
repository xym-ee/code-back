#include <stdio.h>
#include <string.h>

char str[10000];

int check_same_num(const char * s, int index)
{
    int same = -1;  /* 第一次自己和自己比较 */
    for (int i=index; i>=0; i--)
    {
        if (s[index] == s[i])
            same++;
        else
            break;
    }    
    return same;
}

int main()
{
    while( scanf("%s", str) != EOF )
    {
        int len = strlen(str);
        int score = 0;

        for (int i=0; i<len; i++)
        {
            switch (str[i])
            {
            case 'r': score += 1; break;
            case 'g': score += 2; break;
            case 'b': score += 3; break;
            default:
                break;
            }

            score += check_same_num(str, i);
        }

        printf("%d\n", score);
    }

    return 0;
}
