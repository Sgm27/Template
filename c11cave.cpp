#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 500005 
int n,h,lz[maxn];
ll a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>h;
    FOR(i,1,n) 
    {
        int x;
        cin>>x;
        if (i%2) lz[1]++, lz[x+1]--;
        else lz[h-x+1]++;
    }
    ll add=0;
    FOR(i,1,h) 
    {
        add+=lz[i];
        a[i]=add;
    }
    ll Min=*min_element(a+1,a+1+h);
    int cnt=0;
    FOR(i,1,h) 
        if (a[i]==Min) cnt++;
    cout<<Min<<" "<<cnt;
}
