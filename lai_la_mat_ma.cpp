#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
//     freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    getline(cin,s);
    int chu=0,so=0;
    for (int i=0;i<s.length();i++)
        {
            if (s[i]>='0' && s[i]<='9') so++;
            if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) chu++;
         }
    cout<<chu<<"\n"<<so<<"\n"<<s.length()-chu-so;
}

