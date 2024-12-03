#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left=newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }
    if(value < root->data)
    {
        root->left=insert(root->left,value);
    }
    else
    {
        root->right=insert(root->right,value);
    }
};

struct Node*postorder(struct Node*root)
{
    if(root==NULL)
        return NULL;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
};

struct Node*inorder(struct Node*root)
{
    if(root==NULL)
        return NULL;
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
};

struct Node*preorder(struct Node*root)
{
    if(root==NULL)
        return NULL;
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
};

int main()
{
    struct Node* root = NULL;
    int num, value;

    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &num);

    printf("Enter %d values to insert into the binary search tree:\n", num);

    for (int i = 0; i < num; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nPostorder traversal:\n");
    postorder(root);
    printf("\n");

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    return 0;
}
