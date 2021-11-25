#include "function.h"
#include <stdio.h>
//#include <stdlib.h>

#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number
int preorder_idx = 0;
int idxSearch(int arr[], int start, int end, int value)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* newNode(int val)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->num = val;
    node->left = node->right = NULL;
    return node;
}

// 傳入 preorder 和 inorder 序列，以及在 inorder 序列中目前要檢查的範圍
// preorder 或 inorder 序列，都不能有重複的數
Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    if(inorder_start > inorder_end)
        return NULL;

    Node *tree_node = newNode(preorder[preorder_idx]);
    //printf("Tree Built: %d\n",tree_node->num);
    //system("pause");
    preorder_idx++;
    if(inorder_start == inorder_end)
        return tree_node;

    int inorder_idx = idxSearch(inorder, inorder_start, inorder_end, tree_node->num);
    tree_node->left = buildTree(inorder, preorder, inorder_start, inorder_idx-1);
    tree_node->right = buildTree(inorder, preorder, inorder_idx+1, inorder_end);

    return tree_node;
}

void freeTree(Node *root)
{
    if(root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
    preorder_idx = 0;
}

void showPostorder(Node *root)
{
    if (root != NULL) {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->num);
    }
}
