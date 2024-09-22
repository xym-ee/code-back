
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX(a, b)   (((a)>(b)) ? (a) : (b))

int find_dot(char *s, int n)
{
    int dot = n;
    for (int i=0; i<n; i++)
    {
        if (s[i] == '.')
        {
            dot = i;
            break;
        }
    }
    return dot;
}


int main(int argc, char const *argv[])
{
    int len;
    scanf("%d", &len);

    char num1[len + 1];
    scanf("%s", num1);

    int l1 = 0;

    /* 找出第一个加数存放在 num1，长度l1  */
    while (num1[l1++] != '+');
    l1 = l1 - 1;
    num1[l1] = '\0';

    /* 找第 2 个加数 */
    int l2 = len - l1 - 1;
    char num2[l2+1];

    strcpy(num2, &num1[l1 + 1]);

    /* 找小数点位置，让小数点对齐 */
    int dot1 = find_dot(num1, l1);
    int dot2 = find_dot(num2, l2);

    int int_len = MAX(dot1, dot2);
    int flo_len = MAX( l1 - dot1 - 1 , l2 - dot2 - 1);

    int dot = int_len + 1;
    int sum_len = int_len + flo_len + 3;
    char sum1[sum_len];
    char sum2[sum_len];
    char result[sum_len];

    memset(sum1, '0', sizeof(sum1));
    memset(sum2, '0', sizeof(sum2));
    memset(result, '0', sizeof(result));

    sum1[dot] = '.';
    sum2[dot] = '.';
    result[dot] = '.';

    sum1[sum_len - 1] = '\0';
    sum2[sum_len - 1] = '\0';    
    result[sum_len - 1] = '\0'; 

    for (int i = dot1 - 1; i >= 0; i--)
    {
        sum1[dot + i - dot1] = num1[i];
    }
   
    for (int i = dot1; i < l1; i++)
    {
        sum1[dot + i - dot1] = num1[i];
    }

    for (int i = dot2; i >= 0; i--)
    {
        sum2[dot + i - dot2] = num2[i];
    }

    for (int i = dot2; i < l2; i++)
    {
        sum2[dot + i - dot2] = num2[i];
    }

    int carry = 0;
    for (int i = sum_len - 2; i>=0; i--)
    {
        switch (sum1[i])
        {
        case '.':  break;

        case '!':
            switch (sum2[i])
            {
            case '!':
                result[i] = (0 + carry)%10 + '0';
                carry = (0 + carry)/10;
                break;
            case '@':
                result[i] = (13 + carry)%10 + '0';
                carry = (13 + carry)/10;
                break; 
            case '#':
                result[i] = (4 + carry)%10 + '0';
                carry = (4 + carry)/10;
                break;                             
            default:
                break;
            }
        break;

        case '@':
            switch (sum2[i])
            {
            case '!':
                result[i] = (13 + carry)%10 + '0';
                carry = (13 + carry)/10;
                break;
            case '@':
                
                result[i] = (7 + carry)%10 + '0';
                carry = (7 + carry)/10;
                break;
            case '#':
                result[i] = (20 + carry)%10 + '0';
                carry = (20 + carry)/10;
                break;            
            default:
                break;
            } 
        break;

        case '#':
            switch (sum2[i])
            {
            case '!':
                result[i] = (4 + carry)%10 + '0';
                carry = (4 + carry)/10;
                break;                
            case '@':
                result[i] = (20 + carry)%10 + '0';
                carry = (20 + carry)/10;
                break;                
            case '#':
                result[i] = (5 + carry)%10 + '0';
                carry = (5 + carry)/10;
                break;            
            default:
                break;
            }         
        break;
            
        default:
            result[i] = (sum1[i] - '0' + sum2[i] - '0' + carry)%10 + '0';
            carry = (sum1[i] - '0' + sum2[i] - '0' + carry)/10;
            break;
        }
    }

    /* 去掉前后 0 */
    int start = 0;

    for (int i=0; i<dot-1; i++)
    {
        if (result[i] == '0' && start == i)
        {
            start++;
        }
    }    

    int end = sum_len - 1;
    for (int i=end; i>dot; i--)
    {
        if ( result[i - 1] == '0' && result[i] == '\0')
        {
            result[i - 1] = '\0';
        }

        if ( result[i - 1] == '.' && result[i] == '\0')
        {
            result[i-1] = '\0';
            break;
        }
    }

    puts(result + start);
    return 0;
}

