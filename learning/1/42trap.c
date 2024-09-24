
#include <stdio.h>


#define MIN(a, b) (((a)<(b)) ? (a) : (b))
#define MAX(a, b) (((a)>(b)) ? (a) : (b))



int main(int argc, char const *argv[])
{
    int height[100000] = {0};
    
    int count = 0;
    int num;
    int *nums = height;

    while ( scanf("%d,", &num) != EOF )
    {
        nums[count++] = num;
    }

    printf("%d\n", maxArea1(nums, count));

    /* code */
    return 0;
}

