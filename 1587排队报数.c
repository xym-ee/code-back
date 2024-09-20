#include <stdio.h>


int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    int nums[N];

    int out[N];

    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    int height[111];

    for(int i=0; i<111; i++)
        height[i] = 0;

    // for(int i=0; i<111; i++)
    //     printf("%d ", height[i]); 

    for (int i=N-1; i>=0; i--)
    {
        height[nums[i]]++;

        int count = 0;

        for (int j=40; j<nums[i]; j++)
        {
            count += height[j];
        }

        out[i] = count;
    }

    for (int i=0; i<N; i++)
        printf("%d ", out[i]);

    return 0;
}



