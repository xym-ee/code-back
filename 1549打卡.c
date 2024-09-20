#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TIME_TO_MIN(h, m)   (h*60 + m)

#define SLEEP_START         (12*60 + 0)
#define SLEEP_END           (14*60 + 0)

#define DINNER_START        (18*60 + 0)
#define DINNER_END          (19*60 + 30)

int in_time[100];
int out_time[100];

int time[200];


int main(int argc, char const *argv[])
{
    int n, m;
    char time_txt[10];

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%s", time_txt);
        in_time[i] = TIME_TO_MIN(atoi(time_txt), atoi(time_txt + 3));
    }

    scanf("%d", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%s", time_txt);
        out_time[i] = TIME_TO_MIN(atoi(time_txt), atoi(time_txt + 3));
    }

    for (int i=0; i<n; i++)
    {
        if (out_time[i] - in_time[i])



        time[i] = in_time[i];
        time[i+1] = out_time[i];
    }

    // i 进门，  i + 1 出门

    for (int i=0; i<2*n; i++)
    {




    }

    





    return 0;
}






