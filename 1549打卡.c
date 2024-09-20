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

    int sum = 0;

    for (int i=0; i<n; i++)
    {
        int single_time = 0;


        if ( (in_time[i] < SLEEP_START) && (out_time[i] < SLEEP_START) )
        {
            single_time = out_time[i] - in_time[i];
        }
        else if ( (in_time[i] < SLEEP_START) && (out_time[i] > SLEEP_START) )
        {
            single_time = SLEEP_START - in_time[i];
        }
        else if ( (in_time[i] > SLEEP_START) && (out_time[i] < SLEEP_END) )
        {
            single_time = 0;
        }
        else if ( (in_time[i] < SLEEP_END) && (out_time[i] > SLEEP_END) )
        {
            single_time = out_time[i] - SLEEP_START;
        }
        else if ( (in_time[i] > SLEEP_END) && (out_time[i] > SLEEP_END) )
        {
            single_time = out_time[i] - in_time[i];
        }
        else if ( (in_time[i] < SLEEP_START) && (out_time[i] > SLEEP_END) )
        {
            single_time = out_time[i] - SLEEP_END +  SLEEP_START - in_time[i];
        }        

        else if ( (in_time[i] < DINNER_START) && (out_time[i] < DINNER_START) )
        {
            single_time = out_time[i] - in_time[i];
        }
        else if ( (in_time[i] < DINNER_START) && (out_time[i] > DINNER_START) )
        {
            single_time = DINNER_START - in_time[i];
        }
        else if ( (in_time[i] > DINNER_START) && (out_time[i] < DINNER_END) )
        {
            single_time = 0;
        }
        else if ( (in_time[i] < DINNER_END) && (out_time[i] > DINNER_END) )
        {
            single_time = out_time[i] - DINNER_START;
        }
        else if ( (in_time[i] > DINNER_END) && (out_time[i] > DINNER_END) )
        {
            single_time = out_time[i] - in_time[i];
        }
        else if ( (in_time[i] < DINNER_START) && (out_time[i] > DINNER_END) )
        {
            single_time = out_time[i] - DINNER_END +  DINNER_START - in_time[i];
        }

        sum += single_time;

        printf("%d\n", single_time);

        // printf("%d ", in_time[i]);
        // printf("%d\n", out_time[i]);

    }

    printf("%d\n", sum);


    





    return 0;
}






