#include <stdio.h>
#include <stdlib.h>
#include<limits.h>   //有用到最大(INT_MAX)跟最小的數字(INT_MIN),所以要加
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* GetNewNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* Insert(struct Node* root, int data)  //回傳一個節點,所以要用struct
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
int IsBinarySearchTree(struct Node* root,int minValue,int maxValue)   //用大小判斷是不是BST
{
    if(root==NULL) return 1;   //empty tree或葉節點
    if(root->data>minValue    //判斷data是不是在限定的區間
       &&root->data<maxValue
       &&IsBinarySearchTree(root->left,minValue,root->data)   //判斷左樹是不是在最小值跟root之間
       &&IsBinarySearchTree(root->right,root->data,maxValue))    //判斷右樹是不是在最大值跟root之間
        return 1;
    else
        return 0;
}
int main()
{
    struct Node* root = NULL;
    root = Insert(root,15); root = Insert(root, 20);
    root = Insert(root, 17); root = Insert(root, 25);
    root = Insert(root, 14);  root = Insert(root, 30);
    root = Insert(root, 10);  root = Insert(root, 5);
    if(IsBinarySearchTree(root,INT_MIN,INT_MAX)==1) printf("Is binary search tree\n");
    else printf("it is not a binary search tree\n ");
    return 0;
}
