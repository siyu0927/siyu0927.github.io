#include<queue>  //C++的好用函式庫
#include <stdio.h>
#include <stdlib.h>

struct Node   //這次的資料是char形式的
{
    char data;
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

struct Node* Insert(struct Node* root, char data)  //回傳一個節點,所以要用struct
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
void LevelOrder(Node* root)
{
    if(root==NULL) return;  //empty tree 的部分
    std::queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* current=Q.front();
        printf("%c ",current->data);  //印出資料
        if(current->left!=NULL) Q.push(current->left);  //還有左子樹的話加入queue
        if(current->right!=NULL) Q.push(current->right);  //還有右子樹的話加入queue
        Q.pop();  //已經印完的刪除
    }
}

int main()
{
    struct Node* root = NULL;
    root = Insert(root,'D'); root = Insert(root, 'F');
    root = Insert(root, 'C'); root = Insert(root, 'E');
    root = Insert(root, 'B');  root = Insert(root, 'G');
    LevelOrder(root);
    return 0;
} 
