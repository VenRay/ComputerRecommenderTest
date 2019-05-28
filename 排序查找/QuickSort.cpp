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

int Partition (int A[], int low, int high)
{
    int x;
    int pivot = A[low];
    while (low < high)
    {
        while(low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        //x = A[high];
        A[high] = A[low];
        //A[low] = x;
    }
    A[low] = pivot;
    
    return low;
}
void QuickSort(int A[],int low, int high)
{
    if (low < high)
    {
        int mid = Partition(A,low,high);
        QuickSort(A,low,mid - 1);
        Print (A);
        cout<<endl;
        QuickSort(A,mid + 1, high);
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