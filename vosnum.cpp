#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>s;
        string tmp=s;
        sort(s.begin(),s.end());
        int idx=0;
        while (idx<s.length() && s[idx]=='0') idx++;
        if (idx!=s.length()) swap(s[0],s[idx]);
        if (tmp==s) cout<<stoll(s)-1; else cout<<s;
        cout<<"\n";
    }
}

