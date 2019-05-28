#include <iostream>
using namespace std;


int find_key (int a[],int low, int high)
{
    int key;
    key = a[low];

    while (low < high)
    {
        while (low < high && key < a[high])
            high--;
        a[low] = a[high]; 
        while (low < high && key > a[low])
            low++;
        a[high] = a[low];
    }
    a[low] = key;
    return low; 
}

void QuickSort (int a[],int low, int high)
{
    if (low < high)
    {
        int mid = find_key(a,low,high);
        QuickSort (a,low,mid - 1);
        QuickSort (a,mid+1,high);
    }
}

void PrintArray(int a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main()
{
    int a[100];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    PrintArray(a,N);
    QuickSort(a,0,N-1);
    PrintArray(a,N);
    return 0;
}