# include <iostream>
# include <malloc.h>
using namespace std;
const int maxn = 10;

typedef struct node
{
    int data;
    node *left;
    node *right;
}BTree;

typedef struct queue
{
    BTree* data[maxn];
    int rear;
    int front;
}Queue;

BTree *CreateTree()
{
    BTree *root;
    int x;
    cout << "请输入节点元素，0结束"<<endl;
    cin >> x;
    if (x !=0)
    {
        root = (BTree *)malloc (sizeof(BTree));
        root-> data = x;
        root -> left = CreateTree();
        root -> right = CreateTree();
        return root;
    }
    else
    {
        return NULL;
    }   
}

//前序遍历
void PreTravese (BTree * p)
{
    if (p  != NULL)
    {
        cout << p->data <<endl;
        PreTravese(p->left);
        PreTravese(p->right);
    }
    else
    {
        return;
    }
}

void PushQueue (Queue *q,BTree * p) //入队
{
    q->rear  = (q->rear+1)%maxn;
    q ->data[q -> rear] = p;
}
BTree *PopQueue (Queue *q) //出队
{
    q->front  = (q->front+1)%maxn;
    BTree* x = q->data[q -> front];
    return x;
}

//层次遍历
void StrTravese (BTree * p)
{
    Queue *q = (Queue*) malloc (sizeof(Queue));
    BTree *tmp;
    q -> rear = q->front = 0;

    cout << p->data <<endl;
    if (p -> left != NULL)
        PushQueue(q,p -> left);
    if (p -> right != NULL)
        PushQueue(q,p -> right);
    while (q -> rear != q->front)
    {
        tmp = PopQueue (q);
        cout << tmp->data <<endl;
        if (tmp -> left != NULL)
            PushQueue(q,tmp -> left);
        if (tmp -> right != NULL)
            PushQueue(q,tmp -> right);
    }
}

int main()
{
    BTree *root = CreateTree();
    PreTravese(root);
    StrTravese (root);
    return 0;
}
//1 2 4 0 5 0 0 0 3 0 6 0 0