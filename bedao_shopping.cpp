#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
const int N=1e6;
#define maxn 1000006
int f[maxn],n;
void eratos()
{
    f[1]=1;
    FOR(i,2,N) f[i]=2;
    FOR(i,2,sqrt(N))
        for (int j=i*i;j<=N;j+=i) 
        {
            if (i!=j/i) f[j]+=2;
            else f[j]++;
        }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    eratos();
    ll ans=0;
    FOR(i,1,n) ans+=f[i]*f[n-i];
    cout<<ans;
}
