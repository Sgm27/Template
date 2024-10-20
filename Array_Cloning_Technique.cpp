#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 100005
int n,a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        map<int,int> mp;
        cin>>n;
        FOR(i,1,n) cin>>a[i], mp[a[i]]++;
        if (n==1) 
        {
            cout<<"0\n";
            continue;
        }
        int max_fre=0,ans=0;
        for (pii x : mp) max_fre=max(max_fre,x.second);
        while (max_fre<n)
        {
            ans+=1+max_fre;
            max_fre*=2;
        }
        ans-=max_fre-n;
        cout<<ans<<"\n";
    }
}
