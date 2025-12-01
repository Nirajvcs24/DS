#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createNode(int val)
{
    struct TreeNode *newnode=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newnode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inorderTraversal(struct TreeNode *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d\t",root->data);
        inorderTraversal(root->right);
    }
}
void postorderTraversal(struct TreeNode *root)
{
    if(root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t",root->data);
    }
}
void preorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d\t",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
int main()
{
    struct TreeNode *root=createNode(3);
    root->left=createNode(2);
    root->right=createNode(5);
    root->right->left=createNode(4);
    root->right->right=createNode(10);

    printf("\nInOrder Traversal:\n");
    inorderTraversal(root);
    printf("\n");

    printf("\nPreOrder Traversal:\n");
    preorderTraversal(root);
    printf("\n");

    printf("\nPostOrder Traversal:\n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
