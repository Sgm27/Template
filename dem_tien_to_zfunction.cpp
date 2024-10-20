#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
string s;
int n,z[maxn],f[maxn];
void calc_Z()
{
    n=s.length();
    s=" "+s;    
    z[1]=0;
    int l,r=0;
    for (int i=2;i<=n;i++)
    {
        int x=0;
        if (i<=r) x=min(z[i-l+1],r-i+1);
        while (i+x<=n && s[x+1]==s[i+x]) x++;
        z[i]=x;
        f[z[i]]++;
        if (r < i+x-1)
        {
            r=i+x-1;
            l=i;
        }
    }
}
void process()
{
    for (int i=n;i>=1;i--) f[i]+=f[i+1];
    for (int i=1;i<=n;i++) cout<<f[i]+1<<" ";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    calc_Z();
    process();
}

