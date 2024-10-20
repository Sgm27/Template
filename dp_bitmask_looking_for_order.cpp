#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define bit(i,n) ((n>>i)&1)
#define set_on(i,n) ((n) | (1<<i))
#define set_off(i,n) ((n) & ~(1<<i)) 
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 26
int cost[maxn][maxn],n;
pii a[maxn];
vector<int> dp,trace;
int distance(pii a,pii b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int find_lowest_bit(int mask)
{
    for (int i=0;i<n;i++)
        if (bit(i,mask)==0) return i;
    return -1;
}
void process()
{
    dp.resize(1<<n,INF);
    trace.resize(1<<n);
    dp[0]=0;
    for (int mask=0;mask<(1<<n);mask++)
    {
        int i=find_lowest_bit(mask);
        if (i == -1) continue;
        for (int k=0;k<n;k++)
        {
            if (bit(k,mask)) continue;
            // tim bit thap nhat chua duoc bat
            int new_mask=mask | (1<<i) | (1<<k);
            // new_mask bat hai bit i va k(hai bit co the trung nhau nen khong the dung + 1<<i)
            int new_dis=dp[mask]+cost[0][i+1]+cost[i+1][k+1]+cost[k+1][0];
            if (dp[new_mask] > new_dis)
            {
                dp[new_mask]=new_dis;
                trace[new_mask]=mask;
                // danh dau new_mask duoc tao tu mask de truy vet
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
    cout<<0<<" ";
    int mask_answer=(1<<n)-1; 
    // truy vet nguoc tu mask da bat het 
    while (mask_answer)
    {
        int chosen_mask=mask_answer ^ trace[mask_answer]; // off cac bit da chon trong trang thai truoc do
        // chosen mask la trang thai cac do vat duoc chon 
        // khi chuyen tu trace[mask_answer] -> mask_answer
        for (int i=0;i<n;i++)
            if (bit(i,chosen_mask)) cout<<i+1<<" ";
        cout<<"0 ";
        mask_answer=trace[mask_answer];
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>a[0].first>>a[0].second;
    cin>>n;
    FOR(i,1,n) cin>>a[i].first>>a[i].second;
    FOR(i,0,n)
        FOR(j,0,n) cost[i][j]=distance(a[i],a[j]);
    process();
}
