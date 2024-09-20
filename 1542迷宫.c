
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int m;
    scanf("%d", &m);

    int map[2][m];

    for (int i=0; i<2*m; i++)
        scanf("%d", (((int *)map)+i));





        







    for (int i=0; i<2; i++)
    {
        for (int j=0; j<m; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }


    /* code */
    return 0;
}



