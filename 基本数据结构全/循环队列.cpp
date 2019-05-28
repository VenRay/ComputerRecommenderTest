#include <iostream>
#include <malloc.h>
using namespace std;

const int maxn = 10;
typedef struct Node
{
    int data[maxn];
    int rear;
    int front;
}Queue;

Queue *CreateQueue()
{
    Queue *q = (Queue *)malloc (sizeof(Queue));
    q -> rear = q->front = 0;
    return q;
}

void PushQueue (Queue *q, int x)
{
    if (q -> rear+1 == q->front)
    {
        cout << "队满"<<endl;
        return;
    }
    else
    {
        q -> rear = (q->rear+1)%maxn;
        q->data[q->rear] = x;
    } 
}
void PopQueue (Queue *q)
{
    if (q->front == q->rear)
    {
        cout <<"队列为空"<<endl;
        return;
    }
    else
    {
        q -> front = (q ->front+1)%maxn;
    }
}

void PrintQueue(Queue *q) {
    int i;
    i = (q->front + 1) % maxn; //队头加一才开始有元素
    while (i <= q->rear) {
        cout << q->data[i];
        i = (i + 1) % maxn;
    }
}

int main()
{
    Queue *q = CreateQueue();
    cout <<"输入数据0结束"<<endl;
    int x;
    cin >> x;
    while (x!=0)
    {
        PushQueue(q,x);
        cin >> x;
    }
    PrintQueue(q);
    cout <<"输入出队个数"<<endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    PopQueue(q);
    PrintQueue(q);
    return 0;
}