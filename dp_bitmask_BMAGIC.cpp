#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define max_bit 17
#define pii pair<int,int>
const int max_val=60;
#define maxn 105
int n,a[maxn];
vector<int> prime,pri_mask(61);
// prime_mask[i] luu trang thai cac so nguyen to xuat hien trong i
vector<vector<int>> dp,trace;
bool nto(int k)
{
    for (int i=2;i<=sqrt(k);i++)
        if (k%i==0) return 0;
    return 1;
}
void init()
{
    for (int i=2;i<=max_val;i++) 
        if (nto(i)) prime.push_back(i);
    for (int i=0;i<=max_val;i++)
        for (int j=0;j<prime.size();j++)
            if (i % prime[j] == 0) pri_mask[i] |= (1<<j);
    dp.resize(n+1,vector<int>(1<<max_bit,1e9));
    trace.resize(n+1,vector<int>(1<<max_bit));
}
void process()
{
    init();
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
    {
        for (int mask=0;mask<(1<<max_bit);mask++)
            for (int k=1;k<=max_val;k++)
            {
                if (pri_mask[k] & mask) continue;
                int new_mask=mask | pri_mask[k];
                if (dp[i][new_mask] > dp[i-1][mask] + abs(a[i]-k))
                {
                    trace[i][new_mask]=k;
                    dp[i][new_mask] = dp[i-1][mask] + abs(a[i]-k);
                }
            }
    }
    int answer=1e9,mask_ans;
    for (int mask=0;mask<(1<<max_bit);mask++)
        if (dp[n][mask] < answer) 
        {
            answer=dp[n][mask];
            mask_ans=mask;
        }
    vector<int> result;
    for (int i=n;i>=1;i--)
    {
        result.push_back(trace[i][mask_ans]);
        mask_ans = mask_ans ^ pri_mask[trace[i][mask_ans]]; // xoa cac bit cua so vua lay
    }
    reverse(result.begin(),result.end());
    for (int x : result) cout<<x<<" ";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    process();
}
