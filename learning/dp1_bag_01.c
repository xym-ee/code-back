

/* ---------------------------------  01 背包问题模板  --------------------------------- */
#define MAX(a, b)   (((a) > (b)) ? (a) : (b))

int capacity;
int *weight;
int *value;
int n;

// 返回价值
int bag01_dfs(int i, int c)
{
    if ( i < 0 )
        return 0;

    if ( c < weight[i] )
        return 0;

        return MAX(bag01_dfs(i - 1, c), bag01_dfs(i - 1, c - weight[i]) + value[i]);
}



/* 返回最大价值 */
int bag01(int capacity, int *weight, int *value)
{
    return bag01_dfs(n - 1, capacity);
}

/* ----------------------------------     ---------------------------- */













#include <stdio.h>

int result_count = 0;
int sum = 0;

void backtracking(int * nums, int start_index, int nums_len, int target)
{
    if (start_index == nums_len)
    {
        if (sum == target)
        {
            result_count++;
            return;
        }
        else
        {
            return;
        }
    }

    for (int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0: sum += nums[start_index]; break;
        case 1: sum -= nums[start_index]; break;
        default:
            break;
        }

        backtracking(nums, start_index + 1, nums_len, target);

        switch (i)
        {
        case 0: sum -= nums[start_index]; break;
        case 1: sum += nums[start_index]; break;
        default:
            break;
        }
    }
}


int findTargetSumWays(int* nums, int numsSize, int target) {

    backtracking(nums, 0, numsSize, target);

    return result_count; 
}

int main(int argc, char const *argv[])
{
    int target_in;
    scanf("%d", &target_in);
    int nums[20] = {0};
    int count = 0;
    while ( scanf("%d", &nums[count++]) != EOF );
    printf("%d\n", findTargetSumWays(nums, count, target_in));
}

    



