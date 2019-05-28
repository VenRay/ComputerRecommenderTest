#include <iostream>
using namespace std;




void Merge (int a[], int low,int mid, int high)
{
    int b[100];
    for (int i = low; i <= high; i++)
        b[i] = a[i];
    int i,j,k;
    for (i = low,j = mid+1, k = i;i<=mid&&j<=high;k++)
    {
        if (b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];      
    }
    while (i <= mid)
        a[k++] = b[i++];
    while (j <= high)
        a[k++] = b[j++];
}

void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2; 
        MergeSort (a,low,mid);
        MergeSort (a,mid+1,high);
        Merge(a,low,mid,high);
    }
}

void PrintArray (int a[])
{

    int i = 0;
    while (a[i] != 0)
    {
        cout << a[i] <<" ";
        i++;
    }
}

int main()
{
    int a[100];
    cout <<"请输入元素0结束"<<endl;
    int x,i;
    cin >> x ;
    for (i = 0; x != 0; i++)
    {
        a[i] = x;
        cin>>x;
    }
    PrintArray(a);
    cout<<endl;
    MergeSort(a,0,i-1);
    PrintArray(a);
    cout<<endl;
    return 0;

}