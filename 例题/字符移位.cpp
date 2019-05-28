#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int len = s.length();
        int i = len;
        int j = len;
        char key;
        while (i>0 && j> 0)
        {
            while (j > 0 && j--)
                if (s[j] >= 'a' && s[j] <= 'z')
                    break;
            while (i >0 &&  i--)
                if (s[i] >= 'A' && s[i] <= 'Z' && i < j)
                    break;
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                key = s[i];
                for (int k = i; k < j; k++)
                    s[k] = s[k+1];
                s[j] = key;
            }
        }
        cout <<s<<endl;
    }
    return 0;
}
//AkleBiCeilD