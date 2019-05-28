#include <cstdio>

//将一个正整数分解质因数  
//质数相当于天然数
int main()  
{  
    int i,n;  
    //printf("Please input an integer!\n");  
    //scanf("%d",&n);  
    n = 707829217;
    for(i=2;i<=n;i++)  
    {  
        while(n!=i)     //若i=n，则质因数就是n本身  
        {  
            if(n%i==0)  //若i是质因数，则打印出i的值，并用商给n赋新值  
            {  
                printf("%d\n",i);  
                n=n/i;  
            }  
            else break;//若不能被i整除，则算下一个i  
        }  
    }  
    printf("%d\n",n);   //这里是打印最后一个质因数，也就是等于i时的那个  
    return 0;  
}