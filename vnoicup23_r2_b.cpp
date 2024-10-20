#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 105
int n,a[maxn],d[maxn];
vector<int> D[105];
void init()
{
    for (int i=1;i<=100;i++) 
    {
        for (int j=1;j<=sqrt(i);j++) 
            if (i%j==0) 
            {
                D[j].push_back(i);
                if (j!=i/j) D[i/j].push_back(i); 
            }
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        memset(d,0,sizeof(d));
        cin>>n;
        FOR(i,1,n) cin>>a[i], d[a[i]]++;
        int Max1=1,Max2=1;
        FOR(i,1,100)
        {
            int cnt=0;
            for (int x : D[i]) 
                cnt+=d[x];
            if (cnt==2) 
            {
                Max2=Max1;
                Max1=i;
            } 
            if (cnt>=3) Max2=Max1=i;
        }
        cout<<Max2<<"\n";
    }
}
