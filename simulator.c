
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int reg[32];

char opcode[6];
char dst[4];
char src0[11];
char src1[11];

typedef enum {
    MOV = 1,
    ADD,
    SUB,
    MUL,
    DIV,
    PRINT,
}op_t;

op_t decode_and_read(void)
{
    op_t op = 0;

    /* 读 dst */
    scanf("%s", dst);

    /* 读 src0 */
    switch (opcode[0])  /* 根据操作数读取指令 */
    {
    case 'P': op = PRINT; break;
        
    case 'A': op = ADD; scanf("%s", src0); scanf("%s", src1); break;
    case 'S': op = SUB; scanf("%s", src0); scanf("%s", src1); break;
    case 'D': op = DIV; scanf("%s", src0); scanf("%s", src1); break;
    case 'M':
        /* 区分 MOV 和 MUL 读 src1 */
        if (opcode[1] == 'O')
        {
            op = MOV; scanf("%s", src0);
        }
        else
        {
            op = MUL; scanf("%s", src0); scanf("%s", src1);
        }
            
        break;                               
    default:
        break;
    }

    return op;
}

#define REG_NAME_TO_INDEX(s)    atoi(&s[1])
#define IS_REG(s)               (s[0] == 'a')
#define STR_TO_NUM(s)           atoi(s)

void mov(const char* reg_name, const char *src0)
{
    reg[REG_NAME_TO_INDEX(reg_name)] = STR_TO_NUM(src0);
}

void add(const char* reg_name, const char* src0, const char* src1)
{
    int num0, num1;

    if (IS_REG(src0))
        num0 = reg[REG_NAME_TO_INDEX(src0)];
    else
        num0 = STR_TO_NUM(src0);

    if (IS_REG(src1))
        num1 = reg[REG_NAME_TO_INDEX(src1)];
    else
        num1 = STR_TO_NUM(src1);

    reg[REG_NAME_TO_INDEX(reg_name)] = num0 + num1;    
}

void sub(const char* reg_name, const char* src0, const char* src1)
{
    int num0, num1;

    if (IS_REG(src0))
        num0 = reg[REG_NAME_TO_INDEX(src0)];
    else
        num0 = STR_TO_NUM(src0);

    if (IS_REG(src1))
        num1 = reg[REG_NAME_TO_INDEX(src1)];
    else
        num1 = STR_TO_NUM(src1);

    reg[REG_NAME_TO_INDEX(reg_name)] = num0 - num1;        
}

void mul(const char* reg_name, const char* src0, const char* src1)
{
    int num0, num1;

    if (IS_REG(src0))
        num0 = reg[REG_NAME_TO_INDEX(src0)];
    else
        num0 = STR_TO_NUM(src0);

    if (IS_REG(src1))
        num1 = reg[REG_NAME_TO_INDEX(src1)];
    else
        num1 = STR_TO_NUM(src1);

    reg[REG_NAME_TO_INDEX(reg_name)] = num0 * num1;        
}

void mydiv(const char* reg_name, const char* src0, const char* src1)
{
    int num0, num1;

    if (IS_REG(src0))
        num0 = reg[REG_NAME_TO_INDEX(src0)];
    else
        num0 = STR_TO_NUM(src0);

    if (IS_REG(src1))
        num1 = reg[REG_NAME_TO_INDEX(src1)];
    else
        num1 = STR_TO_NUM(src1);

    reg[REG_NAME_TO_INDEX(reg_name)] = num0/num1;

    if ((num0%num1 != 0) &&  (num0<0 || num1<0))
        reg[REG_NAME_TO_INDEX(reg_name)]--;

            
}

void print(const char* reg_name)
{
    printf("%d\n", reg[REG_NAME_TO_INDEX(reg_name)]);    
}

int main()
{
    /* 读取一行指令 */
    while( scanf("%s", opcode) != EOF )
    {
        op_t op = decode_and_read();
        switch (op)
        {
        case MOV: mov(dst, src0);           break;
        case ADD: add(dst, src0, src1);     break;
        case SUB: sub(dst, src0, src1);     break;
        case MUL: mul(dst, src0, src1);     break;
        case DIV: mydiv(dst, src0, src1);     break;
        case PRINT: print(dst);             break;
 
        default:
            break;
        }
        //printf("%d %d %d %d\n", reg[1], reg[2], reg[3], reg[4]);
        //printf("%s %s %s %s\n", opcode, dst, src0, src1);
    }
    return 0;
}





