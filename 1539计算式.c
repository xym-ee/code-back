
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

int result[5000];
int result_len = 0;

void read_num_in_str(char* s, int *nums, int *nums_len)
{
    int str_len = strlen(s);

    s[0] = ' ';
    s[str_len - 2] = '\0';

    *nums_len = 0;
    
    for (int i=1; i<str_len - 1; )
    {
        sscanf(s + i, "%d", &nums[*nums_len]);
        char num[10];
        sprintf(num, "%d", nums[*nums_len]);
        i = i + strlen(num) + 1;
        (*nums_len)++;
    }
}

int len_processadd(int *a, int *b, int a_len, int b_len)
{
    if (a_len > b_len)
    {
        for (int i=b_len; i<a_len; i++)
            b[i] = 0;
        b_len = a_len;
    }
    else if (a_len < b_len)
    {
        for (int i=a_len; i<b_len; i++)
            b[i] = 0;
        a_len = b_len;        
    }

    return a_len;
}

void nums_reverse(int *nums, int len)
{
    int i = 0;
    int j = len - 1;

    while (i<j)
    {
        int num = nums[i];
        nums[i] = nums[j];
        nums[j] = num;
        i++;
        j--;
    }
}

void add(int *a, int *b, int len)
{
    for (int i=0; i<len; i++)
        result[i] = a[i] + b[i];

    result_len = len;
}

void sub(int *a, const int *b, int len)
{
    for (int i=0; i<len; i++)
        result[i] = a[i] - b[i];
    result_len = len;
    
}

void mul(const int *a, int *b, int len)
{
    memset(result, 0, sizeof(result));  // 先将结果清零
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            result[i + j] += a[i] * b[j];  // 逐项乘法，累加到对应阶次的系数
        }
    }
    result_len = 2*len - 1;  // 乘法的最大阶次 
}

int main(int argc, char const *argv[])
{
    char str[10000];

    int a[130];
    int b[130];

    int a_len = 0;
    int b_len = 0;

    fgets(str, sizeof(str), stdin);
    //puts(str); 

    read_num_in_str(str, a, &a_len);
    nums_reverse(a, a_len);
    

    fgets(str, sizeof(str), stdin);
    //puts(str);

    read_num_in_str(str, b, &b_len);
    nums_reverse(b, b_len);
    

    char c;
    scanf("%c", &c);

    int max_len = len_processadd(a, b, a_len, b_len);

    //printf("%d\n", max_len);

    switch (c)
    {
        case '+': add(a, b, max_len); break;
        case '-': sub(a, b, max_len); break; 
        case '*': mul(a, b, max_len); break;
            
    default:
        break;
    }
    nums_reverse(result, result_len);

    putchar('[');

    for (int i=0; i<result_len - 1; i++)
    {
        if (result[i] != 0)
            printf("%d ", result[i]);
    }
        
    printf("%d", result[result_len - 1]);

    putchar(']');

    return 0;
}








