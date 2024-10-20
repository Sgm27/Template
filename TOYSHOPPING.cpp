#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 100005
int n,x,a[maxn],b[maxn];
bool process()
{
    bool sorted=true;
    FOR(i,1,n-1)
        if (a[i]>a[i-1]) 
        {
            sorted=false;
            break;
        }
    if (sorted) return sorted;
    sort(b+1,b+1+n);
    FOR(i,n-x+1,x) 
        if (a[i]!=b[i]) return 0;
    return 1;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>x;
        FOR(i,1,n) cin>>a[i], b[i]=a[i];
        if (process()) cout<<"YES\n";
        else cout<<"NO\n";	
    }    
}
