#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 505
const int N=500;
int prime[N+5],n,k;
void sang()
{
    for (int i=1;i<=N;i++) prime[i]=i;
    for (int i=2;i<=sqrt(N);i++)
        for (int j=i*i;j<=N;j+=i)
            if (prime[j]==j) prime[j]=i;
}
void process(int n,int k)
{
    int cnt[maxn]={};
    for (int i=k+1;i<=n;i++) 
    {
        int tmp=i;
        while (tmp!=1)
        {
            int j=prime[tmp];
            tmp/=j;
            cnt[j]++;
        }
    }
    for (int i=1;i<=n-k;i++)
    {
        int tmp=i;
        while (tmp!=1)
        {
            int j=prime[tmp];
            tmp/=j;
            cnt[j]--;
        }
    }
    ll ans=1;
    for (int i=1;i<maxn;i++) ans*=(cnt[i]+1);
    cout<<ans<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    sang();
    while (cin>>n>>k)
        process(n,k);
}

