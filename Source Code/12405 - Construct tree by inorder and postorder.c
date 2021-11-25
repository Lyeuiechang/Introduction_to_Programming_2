/* C program to construct tree using inorder and
   postorder traversals */
#include <stdio.h>

/* A binary tree node has data, pointer to left
   child and a pointer to right child */
typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

// Utility function to create a new node
Node* newNode(int data);

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);

/* Recursive function to construct binary of size n
   from  Inorder traversal in[] and Postorder traversal
   post[].  Initial values of inStrt and inEnd should
   be 0 and n -1.  The function doesn't do any error
   checking for cases where inorder and postorder
   do not form a tree */
Node* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex)
{
    // Base case
    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Postorder traversal using
       postIndex and decrement postIndex */
    Node* node = newNode(post[*pIndex]);
    (*pIndex)--;

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return node;

    /* Else find the index of this node in Inorder
       traversal */
    int iIndex = search(in, inStrt, inEnd, node->data);

    /* Using index in Inorder traversal, construct left and
       right subtress */
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);

    return node;
}

// This function mainly initializes index of root
// and calls buildUtil()
Node* buildTree(int in[], int post[], int n)
{
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}

/* Function to find index of value in arr[start...end]
   The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

/* This funtcion is here just to test  */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void freeTree(Node *root)
{
    if(root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Driver code
int main()
{
    int id = 0;
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        id++;
        int in[100] = {0};
        int post[100] = {0};
        for(i=0;i<n;i++)
        {
            scanf("%d",&in[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&post[i]);
        }
        Node* root = buildTree(in, post, n);
        printf("testcase%d: ",id);
        preOrder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}
