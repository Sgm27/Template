#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 1005
vector<int> Color[maxn];
int n,m;
struct DT{
    vector<int> vt;
    int idx;
    friend bool operator<(const DT a,const DT b)
    {
        return a.vt < b.vt;
    }
};
vector<DT> listVector;
bool isLower(vector<int> a,vector<int> b)
{
    FOR(i,0,m-1) 
        if (a[i] > b[i]) return false;
    return true;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n)
    {
        vector<int> tmp;
        FOR(j,1,m)
        {
            int x; cin>>x;
            tmp.push_back(x);
        }
        sort(tmp.begin(),tmp.end());
        listVector.push_back({tmp,i});
    }
    sort(listVector.begin(),listVector.end());
    vector<int> f(n,0);
    n--;
    FOR(i,0,n)
    {
        f[i] = 1;
        FOR(j,0,i-1)
            if (isLower(listVector[j].vt,listVector[i].vt)) f[i] = max(f[i], f[j]+1); 
    }
    int numColor = 0;
    FOR(i,0,n) 
    {
        if (f[i] > numColor) numColor = f[i];
        Color[f[i]].push_back(listVector[i].idx);
    }
    cout<<numColor<<"\n";
    FOR(i,1,numColor)
    {
        cout<<Color[i].size()<<" ";
        for (int x : Color[i]) cout<<x<<" "; cout<<"\n";
    }
}
