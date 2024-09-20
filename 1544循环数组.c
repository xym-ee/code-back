
#include <stdio.h>

#define CIR_INDEX(i)  ((i + start)%n)

int find_start(int *num, int len)
{
    int start = 0;
    for (int i=0; i<len - 1; i++)
    {
        if (num[i] > num[i+1])
            start = i + 1;
    }
    return start;
}

int main(int argc, char const *argv[])
{
    /* 读数据 */
    int n;
    scanf("%d", &n);

    int num[n];
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);

    int t;
    scanf("%d", &t);

    int start = find_start(num, n);       /* index 循环数组 */

    int t_start;
    int t_count = 0;

    for (int i=0; i<n ;i++)
    {
        if (num[CIR_INDEX(i)] == t)
        {
            if (t_count == 0)
                t_start = i;

            t_count ++;
        }
    }

    int t_end = t_start + t_count - 1; //开始和节数都是循环数组下标

    //转换到普通数组的下标
    printf("%d %d\n", (t_start + start)%n, (t_end + start)%n);
    
    return 0;
}


