#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 8
int n,cost[maxn][maxn];
string s,t;
unordered_map<string,int> f;
inline void dijkstra(string st)
{
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
    f[st] = 1;
    pq.push({f[st],st});
    while (!pq.empty())
    {
        int du = pq.top().first;
        string u = pq.top().second;
        pq.pop();
        if (du != f[u]) continue;
        if (u == t) 
            return cout<<f[u] - 1, void();
        FOR(i,1,n-1)
            FOR(j,i+1,n)
            {
                swap(u[i-1],u[j-1]);
                if (!f[u] || f[u] > du + cost[i][j])
                {
                    f[u] = du + cost[i][j];
                    pq.push({f[u],u});
                }
                swap(u[i-1],u[j-1]);
            }
    }
}   
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string tmp,token; getline(cin,tmp);
    stringstream ss(tmp);
    while (ss >> token) s += token;
    n = s.size();
    FOR(i,1,n) t += i+'0';
    FOR(i,1,n) FOR(j,1,n) cin>>cost[i][j];
    dijkstra(s);
}
