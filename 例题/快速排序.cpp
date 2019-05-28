#include <iostream>
using namespace std;

void Print (int A[])
{
    int i = 0;
    while (A[i] != 0)
    {
        cout<<A[i]<<" ";
        i++;
    }
}

int  Search (int a[],int low, int high)
{
    if (low > high)
        return 0;
    int key;
    cout<<low<<high<<endl;
    key = a[low];
    while (low < high)
    {
        while (low <high && key <=a[high])
            high--;
        a[low] = a[high];
        while (low < high && key >= a[low])
            low++;
        a[high] = a[low];
    }
    a[low] = key;
    return low;
}

void QuickSort (int a[], int low, int high)
{
    if (low < high)
    {
        int mid = Search(a,low,high);
        QuickSort (a,low,mid-1);
        QuickSort (a,mid+1,high);
    }
}


int main()
{
    int x;
    int i = 0;
    int A[100];
    cout<<"请输入排序序列,0结束"<<endl;
    cin >>x;
    while (x!=0)
    {
        A[i++] = x;
        cin >>x;
    }
    Print (A);
    cout<<endl;
    QuickSort(A,0,i-1);
    Print (A);
    return 0;
}
