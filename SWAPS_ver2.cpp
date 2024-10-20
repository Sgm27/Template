#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,BLOCK_SZ = 1005;
#define maxn 255005
#define maxV 50005
int n,a[maxn],q,numBlock;
struct Fenwick{
    vector<int> t;
    int n;
    void init(int sz)
    {
        n=sz;
        t.assign(n+1,0);
    }
    void update(int x,int val)
    {
        for (;x<=n;x+=x&-x) t[x]+=val;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
} fw[maxn / BLOCK_SZ +1] , fw2;
int CalcINV(int pos,int val)
{
    int change = 0;
    int CurBlock = pos / BLOCK_SZ;
    int add=0,dec=0;
    for (int i = 0;i<CurBlock ;i++)
    {
        change -= fw[i].get(maxV) - fw[i].get(a[pos]);
        change += fw[i].get(maxV) - fw[i].get(val);
    }
    for (int i=CurBlock + 1;i<=numBlock;i++)
    {
        change -= fw[i].get(a[pos]-1);
        change += fw[i].get(val-1);
    }
    int start = CurBlock * BLOCK_SZ;
    int end = min((CurBlock+1) * BLOCK_SZ,n+1);
    for (int i=start ;i<pos;i++)
    {
        if (a[i] > a[pos]) change--;
        if (a[i] > val) change++;
    }
    for (int i = pos + 1;i < end;i++)
    {
        if (a[i] < a[pos]) change--;
        if (a[i] < val) change++;
    }
    return change;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    numBlock = n / BLOCK_SZ;
    FOR(i,0,numBlock) fw[i].init(maxV+5);
    fw2.init(maxV+5);
    int answer = 0;
    FOR(i,1,n) 
    {
        cin>>a[i];
        fw[i / BLOCK_SZ].update(a[i],1);
        answer += fw2.get(maxV) - fw2.get(a[i]);
        fw2.update(a[i],1);
    } 
    cin>>q;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        answer += CalcINV(x,y);
        int CurBlock = x / BLOCK_SZ;
        fw[CurBlock].update(a[x],-1);
        a[x] = y;
        fw[CurBlock].update(a[x],1);
        cout<<answer<<"\n";
    }
}
