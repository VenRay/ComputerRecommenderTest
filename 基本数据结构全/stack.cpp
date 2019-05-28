#include <iostream>
#include <malloc.h>
using namespace std;

const int maxn = 10;
typedef struct Node
{
    int data[maxn];
    int top;
}Stack;

Stack *CreateStack()
{
    Stack *s = (Stack *)malloc (sizeof(Stack));
    s -> top = -1;
    return s;
}

void PushStack (Stack *s,int x)
{
    if (s -> top >= maxn)
    {
        cout <<"栈满" <<endl;
        return ;
    }
    else
    {
        s -> data[++(s -> top)] = x;
    }  
}

void PopStack (Stack *s)
{
    if (s -> top < 0)
    {
        cout <<"栈空"<<endl;
    }
    else
    {
        s -> top--;
    }
}

void PrintStack(Stack *s)
{
    if (s -> top < 0)
    {
        cout <<"栈空"<<endl;
    }
    else
    {
        int tmp = s -> top;
        while (tmp>=0)
        {
            cout << s->data[tmp];
            tmp--;
        }
    } 
}
void DeleteStack(Stack *s)
{
    free (s);
    s = NULL;
}

int main()
{   
    Stack *s = CreateStack();
    cout <<"输入数据0结束"<<endl;
    int x;
    cin >> x;
    while (x!=0)
    {
        PushStack(s,x);
        cin >> x;
    }
    PrintStack(s);
    cout <<"输入出栈个数"<<endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        PopStack(s);
    PrintStack(s);
    DeleteStack(s);

    return 0;
}