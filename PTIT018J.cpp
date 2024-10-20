#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s;
void process()
{
    int n=s.length(),idx=-1,cs;
    for (int i=n-1;i;i--)
        if (s[i]<s[i-1])
        {
            idx=i;
            break;
        } 
    if (idx==-1) return cout<<idx<<"\n", void();
    char Max=0;
    for (int i=idx;i<=n-1;i++) 
        if (s[i]>Max && s[i]<s[idx-1]) Max=s[i], cs=i;
    swap(s[idx-1],s[cs]);
    if (s[0]=='0') return cout<<"-1\n", void();
    cout<<s<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>s;
        process();
    }
}

