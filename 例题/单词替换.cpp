#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main() {
    char s[101][101], a[101], b[101];
    int i,l;
    while(cin>>s[0]) {
        i = 1;
        while(getchar() != '\n') {
            cin>>s[i++];
        }
        cin>>a >> b;
        l = i;
        for (; i >= 0; i--)
            if (!strcmp(s[i], a)) 
                strcpy(s[i], b);
        for (int i =0; i < l ; i++) {
            cout<<s[i];
            if (i < l-1) cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}