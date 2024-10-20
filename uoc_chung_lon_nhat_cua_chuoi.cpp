#include<bits/stdc++.h>
using namespace std;
#define f0(i,n) for (int i=0;i<n;i++)
#define f1(i,n) for (int i=1;i<=n;i++)
using ll = long long;
#define maxn 100005
int n,z[maxn];
string s1,s2;
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
        if (r < i+x-1)
        {
            r=i+x-1;
            l=i;
        }
    }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    calc_Z();
    f1(i,n) cout<<z[i]<<" ";  
}
