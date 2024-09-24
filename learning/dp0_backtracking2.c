
/*
动态规划入门，打家劫舍，回溯的想法

1 <= nums.length <= 100
0 <= nums[i] <= 400

[1,2,3,1]

优化一下，避免重复计算
空间复杂度 O(n)

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b)   (((a) > (b)) ? (a) : (b))

int rob(int* nums, int numsSize) {

    int dp[402] = {0};

    for (int i=0; i<numsSize; i++)
        dp[i+2] = MAX(dp[i+1], dp[i]+ nums[i]);

    return dp[numsSize + 1];
}

int main(int argc, char const *argv[])
{
    int nums[400] = {0};
    int count = 0;

    while ( scanf("%d", &nums[count++]) != EOF );

    printf("%d\n", rob(nums, count));
}


