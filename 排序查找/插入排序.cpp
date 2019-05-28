//前n个有序排列，第n+1个插入
//稳定 n^2
#include <iostream>
using namespace std;

void Print(int *data,int n);

void InsertSort(int data[], int n)
{
    int tmp,key;
    int j,k;
    for (int i = 1; i < n; i++)
    {
        j = 0;
        while (data[j] < data[i])
            j++;
        key = data[i];
        for (int k = i; k > j; k--) //注意从后到前,防止覆盖
        {
            data[k] = data[k-1];
        }
        data[j] = key;
    }
}

void Print(int *data,int n)
{
    cout << data[0];
    for (int i = 1; i < n; i++)
        cout <<" "<< data[i];
    cout << endl;
}

int main()
{
    int n;
    cout << "请输入元素个数"<<endl;
    cin >> n;
    int data[n]; //编译性语言
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    Print(data,n);
    InsertSort(data,n);
    Print (data,n);
    return 0;
}