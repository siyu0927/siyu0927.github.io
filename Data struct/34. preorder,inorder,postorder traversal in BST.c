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
void Preorder(struct Node* root)  //根->左->右
{
    if(root==NULL) return;
    printf("%c ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct Node* root)  //左->根->右
{
    if(root==NULL) return;
    Inorder(root->left);
    printf("%c ",root->data);
    Inorder(root->right);
}
void Postorder(struct Node* root)   //左->右->根
{
    if(root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%c ",root->data);
}
int main()
{
    struct Node* root = NULL;
    root = Insert(root,'F'); root = Insert(root, 'D');
    root = Insert(root, 'J'); root = Insert(root, 'B');
    root = Insert(root, 'E');  root = Insert(root, 'G');
    root = Insert(root, 'K');  root = Insert(root, 'A');
    root = Insert(root, 'C');  root = Insert(root, 'I');
    printf("preorder: ");  Preorder(root);
    printf("\nInorder: ");  Inorder(root);
    printf("\nPostorder: ");  Postorder(root);
    return 0;
}
