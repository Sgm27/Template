#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s;
int n;
void process()
{
    string ans1,ans2;
    string clon,clon2,cbe,cgiua;
    // clon
    int x=((s[0]-'0')+1);
    if (x>=10)
    {
        x%=10;
        for (int i=1;i<=n+1;i++) clon+='1';
    }
    else
    {
        for (int i=1;i<=n;i++) clon+=(x+'0');
    }
    for (int i=1;i<=n;i++)  cgiua+=s[0];
    x=((s[0]-'0')-1);
    if (x==0)
    {
        for (int i=1;i<n;i++) cbe+='9';
    }
    else for (int i=1;i<=n;i++) cbe+=(x+'0');
    // cout<<cbe<<" "<<cgiua<<" "<<clon<<"\n";
    if (s>=cgiua) ans2=cgiua;
    else ans2=cbe;
    if (s<=cgiua) ans1=cgiua;
    else ans1=clon;
    cout<<ans1<<"\n"<<ans2;
}   
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    n=s.length();
    process();
}

