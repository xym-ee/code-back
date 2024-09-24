
#include <stdio.h>


/* 最直接的想法， 暴力算一遍，找最大的，时间复杂度 O(N^2)  */
#define MIN(a, b) (((a)<(b)) ? (a) : (b))
#define MAX(a, b) (((a)>(b)) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int max = 0;
    for (int i = 0; i<heightSize - 1; i++)
    {
        for (int j=i+1; j<heightSize; j++)
        {
            int area = (MIN(height[i], height[j])) * (j - i);

            if (area > max)
                max = area;
        }
    }
    return max;
}


/* 
    思路。想装更多的水，一定要移动当前两个板中最短的。短板效应。主要还是得稍微想一下，然后模拟出来。

    时间复杂度，O(n) 空间复杂度 O(1)
 */
int maxArea1(int* height, int heightSize) {

    int max = 0;

    int l = 0;
    int r = heightSize - 1;

    while (l<r)
    {
        int area = MIN(height[l], height[r]) * (r - l);
        max = MAX(max, area);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return max;
}

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









