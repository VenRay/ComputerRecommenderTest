#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}QueueNode;

typedef struct 
{
    QueueNode *rear;
    QueueNode *front;
}LinkQueue;

LinkQueue *CreateQueue()
{
    LinkQueue *Q;
    Q = (LinkQueue *)malloc (sizeof(QueueNode));
    Q->front = (QueueNode *)malloc(sizeof(QueueNode));
    Q->rear = Q->front;/*头指针和尾指针都指向头结点*/
    Q->front->next = NULL;
    return Q;
}

void QueueDestory(LinkQueue *Q)//销毁队列
{
    QueueNode *cur = Q->front;
    while (cur)
    {
        Q->front = Q->front->next;
        free(cur);
        cur = Q->front;
    }
    Q->front = NULL;
    Q->rear = NULL;
}

//链表的头指针head不储存元素，队列的rear和栈的top有元素,队列的front无元素
void PushQueue(LinkQueue *Q, int x)
{
    QueueNode *NewQueueNode;
    NewQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (NewQueueNode != NULL)
    {
        NewQueueNode->data = x;
        NewQueueNode->next = NULL;
        Q->rear->next = NewQueueNode;/*在队尾插入结点*/
        Q->rear = NewQueueNode;/*修改队尾指针*/
    }
}

void QueuePop(LinkQueue * Q)//出队列
{

    QueueNode *tmp;
    if (Q->front == Q->rear)
    {
        cout<<"空队列，不需出队\n"<<endl;
    }
    tmp = Q->front->next;/*tmp指向队头元素*/
    Q->front->next = tmp->next;/*队头元素tmp出队*/
    if (Q->rear == tmp)/*如果队中只有一个元素tmp，则tmp出队后成为空队*/
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
}

void PrintQueue(LinkQueue *Q) {
    QueueNode *q;
    q = Q -> front->next;
    while (q != Q -> rear )
    {
        cout << q->data <<endl;
        q = q ->next;
    }
    cout << q->data<<endl; //队尾元素
}

int main()
{
    LinkQueue *Q = CreateQueue();
    int n,x;
    cout <<"输入数据个数"<<endl;
    cin >> n;
    cout <<"输入数据"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        PushQueue(Q,x); 
    }
    PrintQueue(Q);
    QueuePop (Q);
    PrintQueue(Q);
    QueueDestory(Q);
    return 0;
}