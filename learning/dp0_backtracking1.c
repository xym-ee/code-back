
/*
动态规划入门，打家劫舍，回溯的想法

1 <= nums.length <= 100
0 <= nums[i] <= 400

[1,2,3,1]

优化一下，避免重复计算

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b)   (((a) > (b)) ? (a) : (b))

int map[400];

int dfs(int index, int *nums)
{
    if (index < 0)
        return 0;

    if (map[index] != -1)
        return map[index];

                /* 当前的不选，当前的选，看看哪个最终的结果更大，一路找到第一个     */
    int res = MAX(dfs(index - 1, nums), nums[index] + dfs(index - 2, nums));
    map[index] = res;
            
    return res;
}

int rob(int* nums, int numsSize) {
    memset(map, 0xff, sizeof(map));
    return dfs(numsSize - 1, nums);
}

int main(int argc, char const *argv[])
{
    int nums[400] = {0};
    int count = 0;

    while ( scanf("%d", &nums[count++]) != EOF );

    printf("%d\n", rob(nums, count));
}


