
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

#define MAX_RESULT_LENGTH       100000

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);
    int **ret = malloc(MAX_RESULT_LENGTH * sizeof(int *));
    int result_len = 0;

    for (int i = 0; i < numsSize - 2; i++)
    {
        for (int j = i + 1; j < numsSize - 1; j++)
        {
            for (int k = j + 1; k < numsSize; k++)
            {
                if ( nums[i] + nums[j] + nums[k] == 0 )
                {
                    if (    result_len > 0 &&
                            nums[i] == ret[result_len - 1][0] &&
                            nums[j] == ret[result_len - 1][1] && 
                            nums[k] == ret[result_len - 1][2]
                     )
                        break;

                    ret[result_len] = malloc(3 * sizeof(int));
                    ret[result_len][0] = nums[i];
                    ret[result_len][1] = nums[j];
                    ret[result_len][2] = nums[k];
                    result_len++;
                }
            }
        }
    }

    *returnSize = result_len;
    *returnColumnSizes = malloc(result_len*sizeof(int));
    for (int i=0; i<result_len; i++)
        (*returnColumnSizes)[i] = 3;
    return ret;
}

/*
    3 遍循环是最容易想到的，但是时间复杂度太高，为 O(N^3) ，而且上年的去重方法是有问题的。

    进行优化。
*/
int** threeSum1(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);
    int **ret = malloc(MAX_RESULT_LENGTH * sizeof(int *));
    int result_len = 0;

    for (int i=0; i<numsSize-2; i++)
    {
        /* 去重的思路 */
        if ( i>0 && nums[i]==nums[i-1])
            continue;

        int l = i+1;
        int r = numsSize - 1;

        while (l<r)
        {
            if ( nums[l] + nums[r] > -nums[i] )
                r--;
            
            else if ( nums[l] + nums[r] < -nums[i] )
                l++;

            else
            {
                ret[result_len] = malloc(3 * sizeof(int));
                ret[result_len][0] = nums[i];
                ret[result_len][1] = nums[l];
                ret[result_len][2] = nums[r];

                result_len++;


                /* 去重的思路 */
                l++;
                while ( (l<r) && (nums[l] == nums[l-1]))
                    l++;
                    
                r--;
                while ( (l<r) && (nums[r] == nums[r+1]))
                    r--;
            }

        }
    }

    *returnSize = result_len;
    *returnColumnSizes = malloc(result_len*sizeof(int));
    for (int i=0; i<result_len; i++)
        (*returnColumnSizes)[i] = 3;
    return ret;
}

/* 还可以优化 */
int** threeSum2(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);
    int **ret = malloc(MAX_RESULT_LENGTH * sizeof(int *));
    int result_len = 0;

    for (int i=0; i<numsSize-2; i++)
    {
        /* 去重的思路 */
        if ( i>0 && nums[i]==nums[i-1])
            continue;

        /* 优化，充分利用排序的结果，后面不可能出现符合要求的结果了 */
        if ( nums[i] + nums[i+1] + nums[i+2] >0 )
            break;

         /* 优化，充分利用排序的结果，直接往后找一个 */
        if ( nums[i] + nums[numsSize-1] + nums[numsSize-2] < 0 )
            continue;;       

        int l = i+1;
        int r = numsSize - 1;

        while (l<r)
        {
            if ( nums[l] + nums[r] > -nums[i] )
                r--;
            
            else if ( nums[l] + nums[r] < -nums[i] )
                l++;

            else
            {
                ret[result_len] = malloc(3 * sizeof(int));
                ret[result_len][0] = nums[i];
                ret[result_len][1] = nums[l];
                ret[result_len][2] = nums[r];

                result_len++;


                /* 去重的思路 */
                l++;
                while ( (l<r) && (nums[l] == nums[l-1]))
                    l++;
                    
                r--;
                while ( (l<r) && (nums[r] == nums[r+1]))
                    r--;
            }

        }
    }

    *returnSize = result_len;
    *returnColumnSizes = malloc(result_len*sizeof(int));
    for (int i=0; i<result_len; i++)
        (*returnColumnSizes)[i] = 3;
    return ret;
}

/*
    时间复杂度 ，快速排序  O(nlogn) 枚举 nums[i] 为 O(n) 双指针也是 O(n) 因此时间复杂度为 O(nlogn) + O(n^2) 或者就是 O(n^2)

    空间复杂度

*/


int main(int argc, char const *argv[])
{
    int num;
    int nums[3000] = {0};
    int count = 0;

    while ( scanf("%d,", &num) != EOF )
    {
        nums[count++] = num;
    }

    for (int i=0; i<count; i++)
        printf("%d ", nums[i]);
    printf("\n");

    int returnSize;
    int* returnColumnSizes;

    // 调用 threeSum 函数
    int** result = threeSum1(nums, count, &returnSize, &returnColumnSizes);

    // 输出结果
    for (int i = 0; i < returnSize; i++) 
    {
        printf("[");

        for (int j = 0; j < returnColumnSizes[i]; j++) 
        {
            printf("%d ", result[i][j]);
        }

        printf("]\n");
    }

}



