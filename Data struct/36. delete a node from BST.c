#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* FindMin(struct Node* root);  //要先聲明返回值的類型和參數,不然會有隱藏bug(乾..debug弄很久欸)
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
struct Node* Delete(struct Node* root,int data)
{
    if(root==NULL) return root;   //empty tree
    else if(data<root->data) root->left=Delete(root->left,data);   //data比root小,往左繼續找
    else if(data>root->data) root->right=Delete(root->right,data);   //data比root大,往右繼續找
    else  //找到了
    {
        if(root->left==NULL&&root->right==NULL)  //無子節點的狀況,直接刪
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)  //只有右節點
        {
            struct Node* temp=root;
            root=root->right;    //把root設到右節點
            free(temp);
        }
        else if(root->right==NULL)  //只有左子節點
        {
            struct Node* temp=root;
            root=root->left;
            free(temp);
        }
        else  //左右都有節點
        {
            struct Node* temp=FindMin(root->right);  //找右邊最小或左邊最大
            root->data=temp->data;  //用最小的值替換掉root
            root->right=Delete(root->right,temp->data);  //recursion刪除
        }

    }
    return root;
}
struct Node* FindMin(struct Node* root)  //recursion
{
    if(root==NULL)   //empty tree
    {
        printf("tree is empty\n");
        return NULL;
    }
    else if(root->left==NULL)   //找到了
    {
        return root;
    }
    return FindMin(root->left);   //一直往左就會是最小的
}
void Preorder(struct Node* root)  //根->左->右
{
    if(root==NULL) return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
    struct Node* root = NULL;
    root = Insert(root,12); root = Insert(root, 5);
    root = Insert(root, 15); root = Insert(root, 3);
    root = Insert(root, 7);  root = Insert(root, 13);
    root = Insert(root, 17);  root = Insert(root, 1);
    root = Insert(root, 9);
    printf("Preorder: ");   Preorder(root);
    printf("\ndelete 15\n ");   Delete(root,15);   Preorder(root);
    return 0;
}
