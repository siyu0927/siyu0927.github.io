//C語言沒有max(),要自己定義
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
int max(int a, int b)
{
    return (a > b) ? a : b;  //如果a>b的話回傳a,不是的話回傳b
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

int FindHeight(struct BSTNode* root)   //recursion
{
    if(root==NULL) return -1;   //找到葉節點了,設-1是因為後面要+1,需抵銷
    return max(FindHeight(root->left),FindHeight(root->right))+1;     
}
int main()
{
    struct BSTNode* root = NULL;
    root = Insert(root, 15); root = Insert(root, 10);
    root = Insert(root, 20); root = Insert(root, 25);
    root = Insert(root, 8);  root = Insert(root, 12);
    printf("height = %d",FindHeight(root));
    return 0;
}
