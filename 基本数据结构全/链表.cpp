#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}LinkList;

LinkList* CreateList (int n)
{
    LinkList *top,*end;
    top = (LinkList *) malloc (sizeof(LinkList));
    end = top; //空指针不用next

    LinkList *p;
    int x;
    for (int i = 0; i < n; i++)
    {
        p = (LinkList* ) malloc (sizeof(LinkList));
        cin >> x;
        p -> data = x;
        end -> next = p;
        end  = p;
    }
    return top;
}

void PrintList(LinkList *p, int n)
{
    LinkList *q = p -> next;
    while (q != NULL)
    {
        cout << q->data<<endl;
        q = q ->next;
    }
}

void DeleteList (LinkList *p)
{
    LinkList *q;
    p = p ->next;
    //关键是free掉内存
    while (p != NULL)
    {
        q = p;
        p = p -> next;
        free(q);       
    }
}

int main()
{
    int n;
    cout <<"输入链表元素个数"<<endl;
    cin >> n;
    LinkList *p = CreateList(n);
    PrintList(p,n);
    DeleteList(p);

    return 0;
}