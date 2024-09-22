
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    unsigned int aa = *(unsigned int *)a;
    unsigned int bb = *(unsigned int *)b;

    if (aa > bb)
        return 1;
    else    
        return -1;
}

int main(int argc, char const *argv[])
{
    unsigned int nums[10000];
    unsigned int num;
    int count = 0;

    while ( scanf("%u,", &num) != EOF)
    {
        nums[count] = num;
        count++;
    }

    qsort(nums, count, sizeof(unsigned int), compare);

    int start = 0;
    int max_len = 0;
    for (int i = 0; i < count - 1; )
    {
        for (int j = i + 1; j<=count; j++)
        {
            if ( (nums[i] + j - i) != nums[j])
            {
                if (j - i > max_len)
                {
                    start = nums[i];
                    max_len = j - i;
                }
                i = j;
                break;
            }
        }
    }

    printf("%d,%d\n", start, max_len);

    return 0;
}


