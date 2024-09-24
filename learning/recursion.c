
/*
递归三要素来写

- 1.递归函数的参数和返回值
- 2.确定终止条件
- 3.确定单层递归的逻辑

*/

/* 例子，二叉树的遍历，前序遍历 */
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void pre_order(struct TreeNode* root, int *size, int *out)
{
    if (root == NULL)
        return;

    out[(*size)] = root->val;
    (*size) ++;

    pre_order(root->left, size, out);
    pre_order(root->right, size, out);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int *ret_array = (int *)malloc(100*sizeof(int));
    *returnSize = 0;

    pre_order(root, returnSize, ret_array);

    return ret_array; 
}




