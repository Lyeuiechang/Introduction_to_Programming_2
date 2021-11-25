#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct TNode{
    int data;
    int index;
    struct TNode* left;
    struct TNode* right;
}TNode;

int A[2000001]={0};

TNode* newNode(int data,int index)
{
    TNode* node = (TNode*)malloc(sizeof(TNode));
    node->data = data;
    node->index = index+1;
    node->left=NULL;
    node->right=NULL;

    return node;
}

void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}

TNode* sortedArrayToBST(int arr[],int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end)/2;
    TNode *root = newNode(arr[mid], mid);

    root->left = sortedArrayToBST(arr, start,mid - 1);

    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// C function to search a given key in a given BST
TNode* search(TNode* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

void freeTree(TNode *root)
{
    if(root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    int n,q,query;
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        TNode *root = sortedArrayToBST(A, 0, n-1);
        //preOrder(root);
        for(i=0;i<q;i++)
        {
            scanf("%d",&query);
            TNode *found = search(root, query);
            if(found == NULL)
            {
                printf("Break your bridge!\n");
            }
            else
            {
                printf("%d\n",found->index);
            }
        }
        for(i=0;i<n;i++)
        {
            A[i] = 0;
        }
        freeTree(root);
    }
    return 0;
}
