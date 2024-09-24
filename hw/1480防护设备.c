#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESS 50
#define MAX_KEY 100
#define MAX_LEN 1000

typedef struct {
    char key[50];
    char value[50];
} KeyValue;

// 替换表达式中的键名为实际值
void replace_key_with_value(char *expression, KeyValue keys[], int key_count) {
    for (int i = 0; i < key_count; i++) {
        char *pos = strstr(expression, keys[i].key);
        while (pos != NULL) {
            char temp[MAX_LEN];
            // 将原始表达式分割并替换
            strncpy(temp, expression, pos - expression);
            temp[pos - expression] = '\0';
            strcat(temp, "'");
            strcat(temp, keys[i].value);
            strcat(temp, "'");
            strcat(temp, pos + strlen(keys[i].key));
            strcpy(expression, temp);
            pos = strstr(expression, keys[i].key);
        }
    }
}

// 替换逻辑运算符 AND -> &&, OR -> ||, = -> ==
void replace_logical_operators(char *expression) {
    char temp[MAX_LEN];
    char *pos;

    // 替换 AND 为 &&
    while ((pos = strstr(expression, "AND")) != NULL) {
        strncpy(temp, expression, pos - expression);
        temp[pos - expression] = '\0';
        strcat(temp, "&&");
        strcat(temp, pos + 3);
        strcpy(expression, temp);
    }

    // 替换 OR 为 ||
    while ((pos = strstr(expression, "OR")) != NULL) {
        strncpy(temp, expression, pos - expression);
        temp[pos - expression] = '\0';
        strcat(temp, "||");
        strcat(temp, pos + 2);
        strcpy(expression, temp);
    }

    // 替换 = 为 ==
    while ((pos = strstr(expression, "=")) != NULL) {
        // 确保是比较操作，而不是类似 '==' 的已经替换过的
        if (*(pos - 1) != '=') {
            strncpy(temp, expression, pos - expression);
            temp[pos - expression] = '\0';
            strcat(temp, "==");
            strcat(temp, pos + 1);
            strcpy(expression, temp);
        }
    }
}

// 一个简单的布尔表达式求值器，暂时只处理 AND 和 OR 以及等式比较
int evaluate_expression(char *expression) {
    // 临时变量存储布尔运算结果
    int result = 0;
    int current_value = 0;
    int is_and = 1;  // 表示是否使用 AND 操作

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (strcmp(token, "&&") == 0) {
            is_and = 1;
        } else if (strcmp(token, "||") == 0) {
            is_and = 0;
        } else if (strstr(token, "==") != NULL) {
            // 找到 == 比较
            char *key_value = strtok(token, "==");
            char *expected_value = strtok(NULL, "==");

            if (strcmp(key_value, expected_value) == 0) {
                current_value = 1;
            } else {
                current_value = 0;
            }

            // 根据是 AND 还是 OR 操作来更新结果
            if (is_and) {
                result = result && current_value;
            } else {
                result = result || current_value;
            }
        }
        token = strtok(NULL, " ");
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char expressions[MAX_EXPRESS][MAX_LEN];
    KeyValue key_value[MAX_KEY];

    // 读取表达式
    for (int i = 0; i < n; i++) {
        getchar(); // 清除换行符
        fgets(expressions[i], MAX_LEN, stdin);
        expressions[i][strcspn(expressions[i], "\n")] = '\0'; // 去除末尾换行符
    }

    // 读取键值对
    for (int i = 0; i < m; i++) {
        scanf("%s %s", key_value[i].key, key_value[i].value);
    }

    // 对每个表达式进行处理
    for (int i = 0; i < n; i++) {
        char expression_copy[MAX_LEN];
        strcpy(expression_copy, expressions[i]);

        // 用键值替换表达式中的字段名
        replace_key_with_value(expression_copy, key_value, m);

        // 替换逻辑运算符
        replace_logical_operators(expression_copy);

        // 解析布尔表达式并输出结果
        if (evaluate_expression(expression_copy)) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }

    return 0;
}
