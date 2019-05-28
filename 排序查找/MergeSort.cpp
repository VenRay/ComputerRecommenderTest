#include <iostream>
using namespace std;

int A[100];
int B[100];

void Print (int A[])
{
    int i = 0;
    while (A[i] != 0)
    {
        cout<<A[i]<<" ";
        i++;
    }
}
void Merge (int A[], int low, int mid, int high)
{ 
    int i,j,k;
    for (k = 0; k <= high; k++)
        B[k] = A[k];
    for (i = low,j = mid+1,k = i; i <= mid && j <= high;k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
        {
            A[k] = B[j++];
        }
    }
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}
void MergeSort (int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        MergeSort (A,low,mid);
        MergeSort (A, mid+1,high);
        Merge(A,low,mid,high);
    }
}

int main()
{
    int x;
    int i = 0;
    cout<<"请输入排序序列,0结束"<<endl;
    cin >>x;
    while (x!=0)
    {
        A[i++] = x;
        cin >>x;
    }
    Print (A);
    cout<<endl;
    MergeSort(A,0,i-1);
    Print (A);
    return 0;
}