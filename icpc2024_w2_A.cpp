#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 205
#define limit maxn*4
int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
// int cam[limit][limit],have[limit][limit];
// bool visited[limit][limit];
vector<vector<int>> cam,have;
vector<vector<bool>> visited;
struct data{
    int x1,y1,x2,y2;
    int type;
} a[maxn*2];
void compress_X()
{
    vector<int> v;
    for (int i=1;i<=n;i++)
        if (a[i].type) 
        {
            v.push_back(a[i].x1);
            v.push_back(a[i].x2);
        }
        else 
            v.push_back(a[i].x1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (int i=1;i<=n;i++)
    {
        if (a[i].type)
        {
            a[i].x1=lower_bound(v.begin(),v.end(),a[i].x1)-v.begin();
            a[i].x2=lower_bound(v.begin(),v.end(),a[i].x2)-v.begin();
            a[i].x1=a[i].x1*2+1;
            a[i].x2=a[i].x2*2+1;
        }
        else
        {
            a[i].x1=lower_bound(v.begin(),v.end(),a[i].x1)-v.begin();
            a[i].x1=a[i].x1*2+1;
        }
    }
}
void compress_Y()
{
    vector<int> v;
    for (int i=1;i<=n;i++)
        if (a[i].type) 
        {
            v.push_back(a[i].y1);
            v.push_back(a[i].y2);
        }
        else 
            v.push_back(a[i].y1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (int i=1;i<=n;i++)
        if (a[i].type)
        {
            a[i].y1=lower_bound(v.begin(),v.end(),a[i].y1)-v.begin();
            a[i].y2=lower_bound(v.begin(),v.end(),a[i].y2)-v.begin();
            a[i].y1=a[i].y1*2+1;
            a[i].y2=a[i].y2*2+1;
        }
        else
        {
            a[i].y1=lower_bound(v.begin(),v.end(),a[i].y1)-v.begin();
            a[i].y1=a[i].y1*2+1;
        }
}
void init()
{
    for (int i=1;i<=n;i++)
    {
        if (a[i].x1==a[i].x2) 
            FOR(j,min(a[i].y1,a[i].y2),max(a[i].y1,a[i].y2)) cam[a[i].x1][j]=1;
        if (a[i].y1==a[i].y2)
            FOR(j,min(a[i].x1,a[i].x2),max(a[i].x1,a[i].x2)) cam[j][a[i].y1]=1;
    }
 
    // FOR(i,n+1,n+m) have[a[i].x1][a[i].y1]=1;
}
void bfs(int i,int j)
{
    visited[i][j]=1;
    int ans=1;
    queue<pii> Q;
    Q.push({i,j});
    while (!Q.empty())
    {   
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        FOR(k,0,3)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if (xx>=0 && yy>=0 && xx<limit && yy<limit && !cam[xx][yy] && !visited[xx][yy])
            {
                Q.push({xx,yy});
                // ans += have[xx][yy];
                visited[xx][yy]=1;
            }
        }
    }
    // return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cam.assign(limit,vector<int>(limit, 0));
        visited.assign(limit,vector<bool>(limit, false));
        cin>>n;
        int ni = 0;
        FOR(i,1,n)
        {
            int aa,bb,cc,dd; 
            cin>>aa>>bb>>cc>>dd;
            ni++;
            a[ni].x1 = aa, a[ni].x2 = aa, a[ni].y1 = dd, a[ni].y2 = bb;
            a[ni].type = 1;
            ni++;
            a[ni].x1 = aa, a[ni].x2 = cc, a[ni].y1 = dd, a[ni].y2 = dd;
            a[ni].type = 1;
            ni++;
            a[ni].x1 = cc, a[ni].x2 = cc, a[ni].y1 = dd, a[ni].y2 = bb;
            a[ni].type = 1;
            ni++;
            a[ni].x1 = aa, a[ni].x2 = cc, a[ni].y1 = bb, a[ni].y2 = bb;
            a[ni].type = 1;
        }
        n = ni;
        // deb(n)
        // FOR(i,1,m)
        // {
        //     cin>>a[i+n].x1>>a[i+n].y1;
        //     a[i+n].type=0;
        // }
        compress_X();
        compress_Y();
        // deb(tc)
        // for (int i=1;i<=n;i++) 
        //     if (a[i].type)
        //         cout<<a[i].x1<<" "<<a[i].y1<<" "<<a[i].x2<<" "<<a[i].y2<<"\n";
        //     else cout<<a[i].x1<<" "<<a[i].y1<<"\n";
        init();
        // deb(visited)
        // deb("done")
        int res=0;
        FOR(i,1,limit-5)
            FOR(j,1,limit-5)
            {
                if (!visited[i][j] && !cam[i][j]) 
                {
                    // if (tc == 0) 
                    // {
                    //     deb(i,j)
                    // }
                    bfs(i,j);
                    res++;
                }
            }
        cout<<res<<"\n";	
    }
}
