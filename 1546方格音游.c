
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int H, V, M;
    scanf("%d %d %d", &H, &V, &M);

    int block[V][H];

    for (int i=0; i< V*H; i++)
    {
        ((int *)block)[i] = i;
    }

    while(M--)
    {
        int ID;
        scanf("%d", &ID);

        int i = ID/H;
        int j = ID%H;

        printf("%d ", block[((i + V) - 1)%V][j]);   //类似循环数组的处理
        if ( j == 0 )
            goto down;
        printf("%d ", block[i][j-1]);
down:;
        printf("%d ", block[((i + V) + 1)%V][j]);
        if ( j == H - 1)
            goto center;
        printf("%d ", block[i][j+1]);
center:;
        printf("%d\n", block[i][j]);
    }
    return 0;
}

