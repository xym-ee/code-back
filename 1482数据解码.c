
#include <stdio.h>
#include <stdlib.h>

unsigned char arr[100000];

char txt[10];

int main(int argc, char const *argv[])
{
    int len = 0;
    while ( scanf("%s", txt) != EOF )
    {
        sscanf(txt, "%hhx", arr + len);
        len++;
    }

    int count = 0;

    for (int i=0; i<len; )
    {
        

        switch (arr[i])
        {
        case 0xF1: i = i + 6;
            count += 4;
            
            break;

        case 0xF0: i = i + 5;
            count += 4;
            /* code */
            break;        
        default:
            printf("%d\n", -1); return 0;
            break;
        }
    }

    printf("%d\n", count);


    // for (int i=0; i<len; i++)
    //     printf("%02X ", arr[i]);
    
    







    return 0;
}





