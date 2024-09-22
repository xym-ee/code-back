#include <stdio.h>

typedef struct
{
    long long int mem[1001];
    int ss;
    int sp;

    void (*push)(long long int);
    long long int (*pop)(void);
} stack_t;

void stack_push(long long int n);
long long int stack_pop(void);

stack_t stack = {
    .ss     = 0,
    .sp     = 0,
    .push   = stack_push,
    .pop    = stack_pop,
};

void stack_push(long long int n)
{
    stack.sp++;
    stack.mem[stack.sp] = n;
}

long long int stack_pop(void)
{
    long long int num = stack.mem[stack.sp]; 
    stack.sp--;
    return num;
}

void sum_check(stack_t *s)
{
    int sum = 0;
    int i;

    for (i = s->sp - 1; i>0; i--)
    {
        sum += s->mem[i];

        if (sum >= s->mem[s->sp])
            break;
    }

    int jj = s->sp - i;

    if (sum == s->mem[s->sp])
    {
        long long int double_top = 2 * s->pop();

        for (int j=0; j < jj; j++)
            s->pop();
        s->push(double_top);
    }
}

void output(void)
{
    for (int i=1; i<=stack.sp; i++)
        printf("%lld ", stack.mem[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    unsigned long long num;

    while( scanf("%llu", &num) != EOF )
    {
        stack.push(num);
        sum_check(&stack);
    }

    int stack_len = stack.sp;
    for (int i=0; i<stack_len; i++)
    {
        printf("%lld ", stack.pop());
    }
    return 0;
}
