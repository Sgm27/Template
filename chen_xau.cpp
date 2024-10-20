#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
   freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        char x;
        string s;
        int k;
        cin>>s>>x>>k;
        for (int i=0;i<k;i++) cout<<s[i];
        cout<<x;
        for (int i=k;i<s.length();i++) cout<<s[i];
        cout<<"\n";	
    }
}

