#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* FindMin(struct Node* root);
struct Node* Find(struct Node* root,int data);  //要先聲明返回值的類型和參數,不然會有隱藏bug
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

struct Node* FindMin(struct Node* root)
{
    if (root == NULL)
    {
        printf("tree is empty\n");
        return NULL;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    return FindMin(root->left);
}

struct Node* Getsuccessor(struct Node* root, int data)
{
    struct Node* current = Find(root, data);  //找到目標點的位置
    if (current == NULL) return NULL;   //successor不存在或empty tree
    if (current->right != NULL)  //有右子樹
    {
        return FindMin(current->right);   //找到最小的
    }
    else   
    {
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while (ancestor != current)   //找到最靠近但比要找得點大的值
        {
            if (current->data < ancestor->data)  //比較小,往左找
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else  //比較大,往右找
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

struct Node* Find(struct Node* root, int data)
{
    if (root == NULL || root->data == data)  //找到了
    {
        return root;
    }
    else if (data < root->data)
    {
        return Find(root->left, data);
    }
    else
    {
        return Find(root->right, data);
    }
}

int main()
{
    struct Node* root = NULL;
    root = Insert(root,15); root = Insert(root, 10);
    root = Insert(root, 20); root = Insert(root, 8);
    root = Insert(root, 12);  root = Insert(root, 17);
    root = Insert(root, 25);  root = Insert(root, 6);
    root = Insert(root, 11);  root = Insert(root, 16);
    root = Insert(root, 27);
    struct Node* successor = Getsuccessor(root, 12);
    printf("12 successor is: %d ",successor->data);

    return 0;
}
