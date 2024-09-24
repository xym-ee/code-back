
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#define MAX(a, b) (((a)>(b)) ? (a) : (b))

int result = 0;

void f(struct TreeNode* root, int count)
{
    if (root == NULL)
        return;
    
    count++;
    result = MAX(count, result);
    f(root->left, count);
    f(root->right, count); 
}

int maxDepth(struct TreeNode* root) {
    f(root, 0);
    return result;
}

int main()
{
    struct TreeNode * root = malloc(sizeof(struct TreeNode));

    root->val = 1;

    root->left = NULL;

    root->right = malloc(sizeof(struct TreeNode));

    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("%d\n", maxDepth(root));

}



