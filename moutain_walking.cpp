#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 105
int n,a[maxn][maxn],visited[maxn][maxn],Max=-1,Min=1e9;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool bfs(int x)
{
    FOR(start,Min,Max-x)
    {
        int end=start+x;
        if (a[1][1]<start || a[1][1]>end) continue;
        FOR(i,1,n) FOR(j,1,n) visited[i][j]=0;
        visited[1][1]=1;
        queue<pii> Q;
        Q.push({1,1});
        while (!Q.empty())
        {
            int xx=Q.front().first;
            int yy=Q.front().second;
            Q.pop();
            if (xx==n && yy==n) return true;
            FOR(k,0,3)
            {
                int nx=xx+dx[k];
                int ny=yy+dy[k];
                if (nx>=1 && nx<=n && ny>=1 && ny<=n && !visited[nx][ny] && a[nx][ny]>=start && a[nx][ny]<=end)
                {
                    visited[nx][ny]=1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    return false;
}
void process()
{
    int l=-1,r=Max-Min;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (bfs(mid)) r=mid;
        else l=mid;
    }
    cout<<r;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j], Max=max(Max,a[i][j]), Min=min(Min,a[i][j]);
    process();
}
