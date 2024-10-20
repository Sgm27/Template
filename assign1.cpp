#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 205
int n,a[maxn][maxn];
struct Point{
    int val;
    set<int> done;
};
Point dp[maxn][maxn];
void process()
{
    FOR(j,1,n)
        FOR(i,1,n)
        {
            FOR(k,1,n) 
                if (!dp[i-1][k].done.count())
        }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j];
    process();
}
