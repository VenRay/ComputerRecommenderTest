#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node
{
    char data;
    Node *left;
    Node *right;
}BTree;

//表达式树
BTree *preCreateBTree()
{
    //前序建树
    //递归的好处是从哪里开始，从哪里回去，最终会回到根节点
    BTree *root;
    char x;
    cin >> x;
    if (x == '0')
        return NULL;
    else
    {
        root = (BTree *)malloc (sizeof(BTree));
        root -> data = x;
        root -> left = preCreateBTree();
        root -> right = preCreateBTree();/* code */
    }
    return root;
}

void midTraver (BTree *root)
{
    if (root == NULL)
        return;
    midTraver(root -> left);
    cout << root -> data <<endl;
    midTraver(root -> right);
}

void deleteTree(BTree *root)
{
    BTree *p,*q;
    if (root == NULL)
        return;
    p = root -> left;
    q = root ->right;
    free(root);
    deleteTree(p);
    deleteTree(q);
}

int main()
{
    BTree *p = preCreateBTree();
    midTraver(p);
    deleteTree(p);
    return 0;
}