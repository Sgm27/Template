#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int n;
struct Fenwick2d{
    vector<vector<int>> t;
    void init(int n)
    {
        t.resize(n+1,vector<int>(n+1));
    }
    void update(int x,int y,int val)
    {
        for (int i=x;i<=n;i+=i&-i) 
            for (int j=y;j<=n;j+=j&-j) t[i][j]+=val;
    }
    int get(int x,int y)
    {
        int ans=0;
        for (int i=x;i>0;i-=i&-i)
            for (int j=y;j>0;j-=j&-j) ans+=t[i][j];
        return ans; 
    }
} fw;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int type;
    while (cin>>type)
    {
        if (type==3) return 0;
        if (type==0)
        {
            cin>>n;
            fw.init(n);
        }
        else
        if (type==1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u++,v++;
            fw.update(u,v,w);
        }
        else
        if (type==2)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            x1++,y1++,x2++,y2++;
            cout<<fw.get(x2,y2)-fw.get(x2,y1-1)-fw.get(x1-1,y2)+fw.get(x1-1,y1-1)<<"\n";
        }
    }
}
