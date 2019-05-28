#include <iostream>
#include <cstdio>
using namespace std;

struct Student
{
    char name[100];
    int score;
}student[100];

int choose;

int find_key (int low, int high)
{
    Student key;
    key = student[low];
    if (choose)
    {
        while (low < high)
        {
            while (low < high && key.score <= student[high].score)
                high--;
            student[low] = student[high]; 
            while (low < high && key.score >= student[low].score)
                low++;
            student[high] = student[low];
        }
    }
    else
    {
        while (low < high)
        {
            while (low < high && key.score >= student[high].score)
                high--;
            student[low] = student[high]; 
            while (low < high && key.score <= student[low].score)
                low++;
            student[high] = student[low];
        }
    }
    
    student[low] = key;
    return low; 
}

void QuickSort (int low, int high,int choose)
{
    if (low < high)
    {
        int mid = find_key(low,high);
        QuickSort (low,mid - 1,choose);
        QuickSort (mid+1,high,choose);
    }
}

void PrintArray(int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << student[i].name << ' '<<student[i].score;
        cout << endl;
    }
}
int main()
{
    int N;
    while (scanf("%d%d",&N,&choose)!= EOF)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> student[i].name;
            cin >> student[i].score;
        }
        //PrintArray(N);
        QuickSort(0,N-1,choose);
        PrintArray(N);
    }
    return 0;
}
/*
3
0
fang 90
yang 50
ning 70
*/
/*
28
1
qhsq 15
ozslg 79
ncttmtsphb 71
a 39
eeiuyzsj 34
nmlrokx 21
pjizylo 90
ec 45
f 12
sh 31
fm 25
ptprphubqk 29
wxdiwv 0
uhlcpjtxad 60
w 20
zwktbpun 70
efzfkf 69
v 31
rsnrgtl 73
lhdo 76
wt 56
mcdwd 14
ydrnoyd 37
gmlfds 76
zx 1
dqx 98
gz 90
kvbzrwrrjj 13
*/