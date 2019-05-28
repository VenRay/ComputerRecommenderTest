#include<iostream>
using namespace std;
int f(int i,int k){
    if(k > i) return f(i,i); //盘子比苹果多，则直接把多余的盘子去掉 
    if(i == 0) return 1;
    if(k == 0) return 0;
    return f(i,k - 1) + f(i - k,k); //苹果比盘子多，则去掉一个盘子和不去盘子 
}
int main(){
    int i,k;
    while(cin>>i>>k){
    cout<<f(i,k)<<endl; 
    } 
    return 0;
} 