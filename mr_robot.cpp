#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int d[256];
void process()
{
    memset(d,0,sizeof(d));
    int cs=10;
    ll res=1,cnt=0;
    if (s[0]=='?' || (s[0]>='A' && s[0]<='J')) 
    {
        res*=9;
        if (s[0]>='A' && s[0]<='J') 
        {
            d[s[0]]=cs-1;
            cs--;
        }
    }
    for (int i=1;i<s.length();i++)
    {
        if (s[i]=='?') cnt++;
        if (s[i]>='A' && s[i]<='J') 
        {
            if (!d[s[i]])
            {
                d[s[i]]=cs--;
                res*=d[s[i]];
            }
        }
    }
    cout<<res;
    for (int i=1;i<=cnt;i++) cout<<"0";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    process();
}

