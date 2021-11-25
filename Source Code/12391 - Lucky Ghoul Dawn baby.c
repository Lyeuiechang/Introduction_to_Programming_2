#include<stdio.h>

int array[2000001] = {0};

/* A Binary Tree node */
typedef struct TNode
{
    int data;
    int index;
    struct TNode* left;
    struct TNode* right;
}TNode;

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
TNode* newNode(int data, int index)
{
    TNode* node = (TNode*)malloc(sizeof(TNode));
    node->data = data;
    node->index = index+1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* A function that constructs Balanced Binary Search Tree from a sorted array */
TNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    TNode *root = newNode(arr[mid], mid);

    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);

    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

/* A utility function to print preorder traversal of BST */
void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
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

void freeBSTTree(TNode *root)
{
    if(root == NULL)
    {
        return;
    }
    freeBSTTree(root->left);
    freeBSTTree(root->right);
    free(root);
}

int main(void)
{
    int i,n,q,ai;
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&array[i]);
        }
        TNode* root = sortedArrayToBST(array, 0, n-1);
        preOrder(root);
        for(i=0;i<q;i++)
        {
            scanf("%d",&ai);
            TNode* query = search(root, ai);
            if(query == NULL)
            {
                printf("Break your bridge!\n");
            }
            else
            {
                printf("%d\n",query->index);
            }
        }
        freeBSTTree(root);
    }
    return 0;
}
