#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
ll n,k,a[maxn],nmax;
ll S[maxn],tong=0;
string s,t;
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    cin>>s>>t;
    int ii=0;
    for (int i=0;i<n;i++) 
    {
        cin>>a[i];
    }
    while (ii<n && s[ii]==t[ii]) ii++;
    int idx=ii;
    ii=n-1;
    while (ii>=idx && s[ii]==t[ii]) 
    {
        ii--;
        n--;
    }
    s[n]='#';
    t[n]='?';
    for (int i=idx;i<n;i++) tong+=a[i];
    ll sum=0;
    while (idx<=n)
    {
        if (s[idx]!=t[idx])
        {
            if (sum) S[++nmax]=sum;
            sum=0;
        }
        else sum+=a[idx];
        idx++;
    }
    sort(S+1,S+1+nmax);
    k--;
    while (k-- && nmax)
    {
        tong-=S[nmax--];
    }
    cout<<tong;
}
