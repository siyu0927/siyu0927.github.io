#include <stdio.h>
#include <stdlib.h>

struct BSTNode
{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BSTNode* GetNewNode(int data)
{
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BSTNode* Insert(struct BSTNode* root, int data)  //回傳一個節點,所以要用struct
{
    if (root == NULL)  //表示empty tree
    {
        root = GetNewNode(data);  //設root
    }
    else if (data <= root->data)   //插入的小於root,往左
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);  //插入得比root大,往右
    }
    return root;
}
int FindMin(struct BSTNode* root)  //recursion
{
    if(root==NULL)   //empty tree
    {
        printf("tree is empty\n");
        return -1;
    }
    else if(root->left==NULL)   //找到了
    {
        return root->data;
    }
    return FindMin(root->left);   //一直往左就會是最小的
}
int FindMax(struct BSTNode* root)  //一直往右就會是最大的
{
    if(root==NULL)
    {
        printf("tree is empty\n");
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->data;
    }
    return FindMax(root->right);
}
int main()
{
    struct BSTNode* root = NULL;
    root = Insert(root, 15); root = Insert(root, 10);
    root = Insert(root, 20); root = Insert(root, 25);
    root = Insert(root, 8);  root = Insert(root, 12);
    printf("min is: %d\n",FindMin(root));
    printf("max is: %d\n",FindMax(root));
    return 0;
}
