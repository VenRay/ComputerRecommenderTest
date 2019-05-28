#include <malloc.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}*LNode;

LNode CreatList ()
{
    LNode L;
    LNode p = L;
    int n;
    int x;
    L = (LNode) malloc (sizeof(LNode));
    L ->next = NULL;
    cout <<"请输入链表元素个数"<<endl;
    cin >> n;
    cout <<"请输入链表元素"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >>x;
        p = (LNode) malloc (sizeof(LNode));
        p -> data = x;
        p -> next = L -> next;
        L -> next = p;
    }
    return L;
}
void PrintList(LNode L)
{
    LNode p = L->next;
    while (p  != NULL)
    {
        cout << p-> data <<" ";
        p = p -> next;
    }
}

int main()
{
    LNode L = CreatList ();
    PrintList(L);
    return 0;
}
