
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void *a, const void *b)
{
    int aa = *(int *)a;
    int bb = *(int *)b;

    return bb - aa;
}

int main(int argc, char const *argv[])
{
    int n, single_num;

    char str[2000000];

    scanf("%d", &n);
    scanf("%d", &single_num);
    scanf("%s", str);

    int ascii[256];

    memset(ascii, 0, sizeof(ascii));

    int sort[256];

    int i = 0;
    while (str[i] != '\0')
    {
        if (i%single_num == 0)
        {
            memcpy(sort, ascii, sizeof(sort));
            qsort(sort, 256, sizeof(int), compare);

            for (int i=0; i<n; i++)
            {
                int j = 0;
                for (; j<256; j++)
                {
                    if (sort[i] == ascii[j])
                        break;
                }

                printf("%c", j);
                
            }

        }

        ascii[str[i]]++;
        i++;
    }

    //puts(str);


    return 0;
}










