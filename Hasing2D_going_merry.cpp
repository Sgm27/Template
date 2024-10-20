#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
const int baseX=27,baseY=29;
#define maxn 1005 
int N,M,R,C;
vector<vector<int>> s,t;
int PX[maxn],PY[maxn];
void build_Pow()
{
    PX[0]=PY[0]=1;
    FOR(i,1,maxn-2)
        PX[i]=(PX[i-1]*baseX)%MOD, PY[i]=(PY[i-1]*baseY)%MOD;
}
struct Hasing_2D{
    vector<vector<int>> hs;
    int n,m;
    Hasing_2D() {}
    Hasing_2D(vector<vector<int>> s,int N,int M)
    {
        n=N,m=M;
        hs.resize(n+5,vector<int>(m+5));
        FOR(i,0,n-1)
            FOR(j,0,m-1)
                hs[i+1][j+1]=s[i][j];
        FOR(i,0,n)
            FOR(j,0,m-1)
            {
                hs[i][j+1]=(hs[i][j+1]+hs[i][j]*baseY%MOD)%MOD;
            }        
        FOR(i,0,n-1)
            FOR(j,0,m)
            {
                hs[i+1][j]=(hs[i+1][j]+hs[i][j]*baseX%MOD)%MOD;
            }
    } 
    int get_hash(int x1,int y1,int x2,int y2)
    {
        x1--;
        y1--;
        int dx=x2-x1, dy=y2-y1;
        return ((hs[x2][y2]-hs[x2][y1]*PY[dy]%MOD+MOD)%MOD
            -(hs[x1][y2]-hs[x1][y1]*PY[dy]%MOD+MOD)%MOD*PX[dx]%MOD+MOD)%MOD;
    }
    int get_hash()
    {
        return get_hash(1,1,n,m);
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    build_Pow();
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>N>>M;
        s.resize(N+5,vector<int>(M+5));
        FOR(i,0,N-1)
            FOR(j,0,M-1)
            {
                char x; cin>>x;
                s[i][j]=(x-'a'+1);
            }
        Hasing_2D HashS(s,N,M);
        cin>>R>>C;
        t.resize(R+5,vector<int>(C+5));
        FOR(i,0,R-1)
            FOR(j,0,C-1)
            {
                char x; cin>>x;
                t[i][j]=(x-'a'+1);
            }
        int HashT=Hasing_2D(t,R,C).get_hash(),flag=0,ans=0;
        FOR(i,1,N)
        {
            FOR(j,1,M)
                if (i+R-1<=N && j+C-1<=M)
                {
                    if (HashS.get_hash(i,j,i+R-1,j+C-1)==HashT) 
                    // {
                    //     cout<<"YES\n";
                    //     flag=1;
                    //     break;
                    // }
                    ans++;
                }
            // if (flag) break;
        }
        // if (!flag) cout<<"NO\n";
        cout<<ans<<"\n";
    }
}
