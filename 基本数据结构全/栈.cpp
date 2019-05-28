#include <cstdio>

#define MAX_SIZE 10  // 存储元素的最大个数
#define ERROE -1
#define bool int
#define True 1
#define Flase 0
// element_type 代表任意基本数据类型
typedef int element_type;


typedef struct{
    element_type data[MAX_SIZE];
    int top;
} stack;

// 入栈
void push(stack *s, element_type item)
{
    if (s->top < MAX_SIZE-1){
        s->data[(s->top)+1] = item;
        s->top++;
    }
}

// 出栈
element_type pop(stack *s)
{
    element_type n = NULL;
    if (s->top != -1){
        n = s->data[(s->top--)];
    }
    return n;
}

// 判断堆栈是否为空
bool is_empty(stack *s)
{
    bool flag = Flase;
    if (s->top == -1){
        flag = True;
    }
    
    return flag;
}

// 判断堆栈是否已满
bool is_full(stack *s)
{
    bool flag = Flase;
    if (s->top == MAX_SIZE-1){
        flag = True;
    }
    
    return flag;
}