#include"function.h"


Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    int preorder_idx = 0;
    if(inorder_start > inorder_end)
        return NULL;
    Node *tree_node = newNode(preorder[preorder_idx++]);
    if(inorder_start == inorder_end)
        return tree_node;
    int inorder_idx;
    for(int i=0;i<sizeof(preorder);i++)
    {
        if(preorder[i]==inorder[0])
        {
            inorder_idx = i;
            break;
        }
    }
    tree_node->left = buildTree(inorder,preorder,inorder_start,inorder_idx-1);
    tree_node->right = buildTree(inorder,preorder,inorder_idx+1,inorder_end);
    return tree_node;
}

void showPostorder(Node* root)
{
    if(root!=NULL)
    {
        showPostorder(root->ptr_to_left_node);
        showPostorder(root->ptr_to_right_node);
        printf("%d "->root->number);
    }
}

void freeTree(Node *root)
{
    if(root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}