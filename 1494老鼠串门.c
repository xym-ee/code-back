
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int mem[10001];
    int ss;
    int sp;
} stack_t;

stack_t home = {
    .ss     = 1,
    .sp     = 0,
};

stack_t wait = {
    .ss     = 1,
    .sp     = 0,
};

void push(stack_t *s, int n)
{
    (s->sp)++;
    s->mem[s->sp] = n;
}

int pop(stack_t *s)
{
    int num = s->mem[s->sp]; 
    (s->sp)--;
    return num;
}

void output(stack_t *s)
{
    int len = s->sp;
    for (int i=1; i<=len; i++)
        printf("%d ", s->mem[i]);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    int num;
    int max_in_num = 0;
    int set_flag = 0;

    char str[10];

    while( scanf("%s", str) != EOF )
    {
        num = atoi(str);

        if (set_flag)
        {
            max_in_num = 0;
        }

        //printf("%d ", num);

        if ( num > max_in_num )
        {
            max_in_num = num;
            push(&home, num);

            output(&home);
        }

        else
        {
            int pop_num = max_in_num - num + 1;
            // printf("%d %d\n", max_in_num, num);

            for (int i=0; i<pop_num; i++)
            {
                int temp = pop(&home);

                output(&home);

                //printf("%d ", temp);
            }

            push(&home, num);

           

            set_flag = 1;
        }
    }

    int home_len = home.sp;

    for (int i=0; i<home_len; i++)
        printf("%d ", pop(&home));

    return 0;
}
















