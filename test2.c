#include <stdio.h>
#include <stdlib.h>

// 比较函数,用于判断数组是否有序
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int T; // 测试用例个数
    scanf("%d", &T);
    
    while (T--) {
        int n; // 数组长度
        scanf("%d", &n);
        
        int a[n], b[n]; // 两个数组
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        
        // 对a和b分别进行排序
        qsort(a, n, sizeof(int), cmp);
        qsort(b, n, sizeof(int), cmp);
        
        // 判断是否至少有一个数组有序
        int is_a_ordered = 1, is_b_ordered = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                is_a_ordered = 0;
                break;
            }
            if (b[i] > b[i + 1]) {
                is_b_ordered = 0;
                break;
            }
        }
        
        // 输出结果
        if (is_a_ordered || is_b_ordered) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}




