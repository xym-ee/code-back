#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return -(*(int*)a - *(int*)b);
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++)
    {
        int N, n, c;
        scanf("%d %d %d", &N, &n, &c);
        
        int toys[n];
        
        for (int i=0; i<n; i++)
        {
            scanf("%d", &toys[i]);
        }

        qsort(toys, n, sizeof(int), compare);
 
        int sum = 0;

        int j;
        
        for (j=0; j<n; j++)
        {
            sum += toys[j];
            
            if (sum == N)
            {
                printf("YES\n");

                goto end;
            }
            else if (sum > N)
            {
                sum -= toys[j];
                
                if ((sum < N) && (c >= N - sum))
                {
                    printf("YES\n");
                    goto end;
                }
                else
                {
                    printf("NO\n");
                    goto end;

                }

            }
            
        }
        end:;
    }
}

