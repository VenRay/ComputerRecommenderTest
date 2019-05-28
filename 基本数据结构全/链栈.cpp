#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char data;
    struct node *next;
}Lstack,*Lpstack;

//链栈实际是只能在头部操作的链表
void initStack(Lstack **top)
{
    if(((*top)=(Lstack *)malloc(sizeof(Lstack)))==NULL)
        exit(-1);
    (*top)->next=NULL;
}

void Push(Lstack *top,char e)
{
    Lstack *p;
    if((p=(Lstack *)malloc(sizeof(Lstack)))==NULL)
    {
        printf("分配内存失败！\n");
        exit(-1);
    }
    p->next=top->next;
    p->data=e;
    top->next=p;
}
int Pop(Lstack *top)
{
    Lstack *p;
    p=top->next;
    if(p==NULL){
        printf("内存已空!\n");
        return 0;
    }
    char e=p->data;
    top->next=p->next;
    free(p);
    return e;
}

int getLength(Lstack *top)
{
    int cnt=0;
    Lstack *p=top;
    while(p->next!=NULL){
        p=p->next;
        cnt++;
    }
    return cnt;
}
char getTop(Lstack *top,char e)
{
    Lstack *p;
    p=top->next;
    if(p==NULL){
        printf("栈已空！\n");
        return 0;
    }
    e=p->data;
    return e;
}
void clear(Lstack *top)
{
    Lstack *p,*q;
    p=top;
    while(!p){
        q=p;
        p=p->next;
        free(q);
    }
}
int main()
{
    char e;
    char a[15];
    int i,len;
    Lstack *s;
    scanf("%s",a);
    initStack(&s);
    len=strlen(a);
    for(i=0;i<len;i++){
        Push(s,a[i]);
    }
    printf("len = %d\n",getLength(s));
    printf("弹出栈顶元素! \n");
    e = Pop(s);
    printf("len = %d\n",getLength(s));

    printf("取得栈顶元素：%c\n",getTop(s,e));

    printf("Clear Stack!\n");
    clear(s);
    printf("len = %d\n",getLength(s));

    while(s->next){
        printf("%c ",getTop(s,e));
        e = Pop(s);
    }
    printf("len = %d\n",getLength(s));
    return 0;
}