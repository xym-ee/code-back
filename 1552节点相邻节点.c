
#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
    long int aa = *(long int*)a;
    long int bb = *(long int*)b;

    if (aa-bb > 0)
        return 1;
    else{
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int m;
    scanf("%d", &m);

    int port[m];

    for (int i=0; i<m; i++)
    {
        scanf("%d", &port[i]);
    }
        
    int n;
    scanf("%d", &n);

    int count = 0;
    long int out[n];

    /* 处理一组数据 */
    for (int i=0; i<n; i++)
    {
        long int name_in;
        scanf("%ld", &name_in);

        int port_in_num;
        scanf("%d", &port_in_num);

        int port_in[port_in_num];

        /* 读取一组中的输入端口 */
        for (int j=0; j<port_in_num; j++)
        {
            scanf("%d", &port_in[j]);
        }

        for (int j=0; j<port_in_num; j++)
        {
            for (int k=0; k<m; k++)
            {
                if (port[k] == port_in[j])
                {
                    out[count] = name_in;
                    count++;
                    goto next_name;
                }
            }            
        }
    next_name:;
    }


    qsort(out, count, sizeof(long int), compare);

    printf("%d\n", count);
    for (int i=0; i<count; i++)
        printf("%ld ", out[i]);
    return 0;
}




