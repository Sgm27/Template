#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
#define maxn 505
#define inf -1000000007
int n,m,k,ts_am,ts_duong,d[maxn],a[maxn][maxn];
vector<pair<int,int>> ke[maxn];
void input()
{
    ts_am=ts_duong=0;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) a[i][j]=inf;
    for (int i=1;i<=n;i++) ke[i].clear();
    for (int i=1;i<=m;i++)
    {
        int s,e,t;
        cin>>s>>e>>t;
        a[s][e]=-t;
        a[e][s]=-t;
        ke[s].push_back({e,-t});
        ke[e].push_back({s,-t});
        ts_am+=t;
    }
    for (int i=1;i<=k;i++)
    {
        int s,e,t;
        cin>>s>>e>>t;
        a[s][e]=t;
        ke[s].push_back({e,t});
        ts_duong+=t;
    }
}
void Fordbellman(int s)
{
    fill(d+1,d+1+n,inf);
    d[s]=0;
    while (1)
    {
        bool stop=true;
        for (int u=1;u<=n;u++)
            for (pair<int,int> it : ke[u])
            {
                int v=it.first;
                int w=it.second;
                if (d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    stop=false;
                }
            }
        if (stop) break;
    }
}
bool check(int s)
{
    for (int i=1;i<=n;i++)
    {
        if (d[i]+a[i][s]>0) return true;
    }
    return false;
}
void process()
{
    if (ts_am>ts_duong) 
    {
        cout<<"NO\n";
        return;
    }
    for (int i=1;i<=n;i++)
    {
        Fordbellman(i);
        if (check(i)) 
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        input();
        process();
    }
}

