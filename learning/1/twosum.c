
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int *ret = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i=0; i<numbersSize - 1; i++)
    {
        for (int j = i+1; j<numbersSize; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    *returnSize = 0;
    free(ret);
    return NULL; 
}

/*
    暴力枚举最容易想到的方法，时间复杂度 O(N^2)，但是在 leetcode 有一些用例会超时。

    此题号为 167，输入数组为有序数组，想办法使用这个信息。

    思路：
    直接选小的和最大的，加起来如果大于目标，那么说明最大的选大了，把最大的去掉。
    加起来小于目标，说明最小的选小了，去掉最小的。

    时间复杂度分析，每次比较式 O(1) 的时间，最多比较 n 此也就结束了。空间复杂度，O(1) 只用了几个额外变量

    相向双指针
*/
int* twoSum1(int* numbers, int numbersSize, int target, int* returnSize) {

    int *ret = malloc(2 * sizeof(int));
    *returnSize = 2;

    int l = 0;
    int r = numbersSize - 1;

    while (l < r)
    {
        if ( numbers[l] + numbers[r] > target )
            r--;
        
        if ( numbers[l] + numbers[r] < target )
            l++;

        if ( numbers[l] + numbers[r] == target )
        {
            ret[0] = l + 1;
            ret[1] = r + 1;
            return ret;            
        }

    }

    *returnSize = 0;
    free(ret);
    return NULL; 
}



int main(int argc, char const *argv[])
{
    int target;
    scanf("%d", &target);

    int num;
    int nums[30000] = {0};
    int count = 0;

    while ( scanf("%d", &num) != EOF )
    {
        nums[count++] = num;
    }

    int ret_size;
    int *ret = twoSum1(nums, count, target, &ret_size);

    printf("[%d,%d]", ret[0], ret[1]);

    free(ret);    
}






