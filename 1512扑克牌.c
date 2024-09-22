
#include <stdio.h>

typedef struct
{
    char mem[53];
    int ss;
    int sp;
} stack_t;

stack_t stack = {
    .ss     = 1,
    .sp     = 0,
};

void stack_push(char  n)
{
    stack.sp++;
    stack.mem[stack.sp] = n;
}

char  stack_pop(void)
{
    char num = stack.mem[stack.sp]; 
    stack.sp--;
    return num;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char str[10];

    for (int i=0; i<n; i++)
    {
        scanf("%s", str);
        stack_push(str[0]);

        if ( stack.mem[stack.sp] == stack.mem[stack.sp - 1] )
        {
            if ( stack.mem[stack.sp] == stack.mem[stack.sp - 2] )
            {
                stack_pop();
                stack_pop();
                stack_pop();
            }
        }
    }

    if (stack.sp == 0)
        printf("0\n");

    int len = stack.sp;
    for (int i=1; i<=len; i++)
        printf("%c ", stack.mem[i]);
}

