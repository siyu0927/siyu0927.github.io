#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool Search(struct BSTNode* root, int data)
{
    if (root == NULL) return false;  //代表empty tree
    else if (root->data == data) return true;   //有找到
    else if (data <= root->data) return Search(root->left, data);    //比root小,繼續往左邊找
    else return Search(root->right, data);   //比root大,往右邊找
}

int main()
{
    struct BSTNode* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int number;
    printf("Enter a number to search: ");
    scanf("%d", &number);

    if (Search(root, number) == true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}
