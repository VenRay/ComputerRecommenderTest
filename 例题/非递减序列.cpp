#include<iostream>
using namespace std;
//0x3f3f3f3f
int main(){
    int n;
    cin>>n;
    int a[n];
    int i;
    int res=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        res^=a[i];
    }
     
    cout<<res;
}