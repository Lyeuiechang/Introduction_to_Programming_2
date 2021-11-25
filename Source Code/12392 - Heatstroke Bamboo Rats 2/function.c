#include<stdio.h>
#include<string.h>
#include "function.h"
#define MAX_N 10004

/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->level = data;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}

/* A function that constructs Balanced Binary Search Tree from a sorted array */
Node* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = newNode(arr[mid]);

    /* Recursively construct the left subtree and make it
       left child of root */
    root->left_child = sortedArrayToBST(arr, start, mid-1);

    /* Recursively construct the right subtree and make it
       right child of root */
    root->right_child = sortedArrayToBST(arr, mid+1, end);

    return root;
}

/* A utility function to print preorder traversal of BST */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->level);
    preOrder(node->left_child);
    preOrder(node->right_child);
}

void build_tree(Node **now, int *arr, int l, int r)
{
    *now = sortedArrayToBST(arr, l, r);
    //preOrder(*now);
}

// C function to search a given key in a given BST
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->level == key)
       return root;

    // Key is greater than root's key
    if (root->level < key)
       return search(root->right_child, key);

    // Key is smaller than root's key
    return search(root->left_child, key);
}

int query_heatstroke(Node *now, int x)
{
    Node*query = search(now, x);
    if(query != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
Node* minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left_child != NULL)
        current = current->left_child;

    return current;
}
Node* deleteNode(Node* root, int key)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->level)
    {
        root->left_child = deleteNode(root->left_child, key);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->level)
    {
        root->right_child = deleteNode(root->right_child, key);
    }
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left_child == NULL)
        {
            Node *temp = root->right_child;
            free(root);
            return temp;
        }
        else if (root->right_child == NULL)
        {
            Node *temp = root->left_child;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = minValueNode(root->right_child);

        // Copy the inorder successor's content to this node
        root->level = temp->level;

        // Delete the inorder successor
        root->right_child = deleteNode(root->right_child, temp->level);
    }
    return root;
}

void eat_rat(Node **root, int x)
{
    *root = deleteNode(*root, x);
}

/* A utility function to insert a new node with given key in * BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key <= node->level)
        node->left_child = insert(node->left_child, key);
    else if (key > node->level)
        node->right_child = insert(node->right_child, key);

    /* return the (unchanged) node pointer */
    return node;
}

void buy_rat(Node **root, int x)
{
    *root = insert(*root, x);
}
