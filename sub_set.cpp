#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1000005
int a[maxn],l,r,dp[maxn],n,trace[maxn],sum,pos[maxn];
pii X[maxn];
bool check_same=true,check_inc=true,have=false;

void sub1()
{
    int mask_ans;
    for (int mask=1;mask<(1<<n);mask++)
    {
        int S=0;
        for (int i=1;i<=n;i++)
        {
            int j=i-1;
            if ((mask>>j)&1) S+=a[j+1];
        }
        if (S>=l && S<=r) 
        {
            mask_ans=mask;
            break;
        }
    }   
    cout<<__builtin_popcount(mask_ans)<<"\n";
    for (int i=0;i<n;i++)
        if ((mask_ans>>i)&1) cout<<i+1<<" ";
}


void sub2()
{
    FOR(i,1,n) X[i].first=a[i], X[i].second=i;
    map<int,int> Trace;
    set<int> dp;
    dp.insert(0);
    sort(X+1,X+1+n,greater<pii>());
    int S,flag=0;
    FOR(i,1,n)
    {
        vector<int> v;
        for (int x : dp) 
            if (!dp.count(x+X[i].first))
            {
                v.push_back(x+X[i].first);
                if (!Trace[x+X[i].first]) Trace[x+X[i].first]=X[i].second;
                if (x+X[i].first>=l && x+X[i].first<=r)
                {
                    S=x+X[i].first;
                    flag=1;
                    break;
                }
            }
        for (int x : v) dp.insert(x);
        if (flag) break;
    }
    vector<int>ans;
    while (S)
    {
        ans.push_back(Trace[S]);
        S-=a[Trace[S]];
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for (int x : ans) cout<<x<<" ";
}

void sub3_sub6()
{
    dp[0]=1;
    int s,flag=0;
    FOR(i,1,n)
    {
        FOD(j,r,a[i]) 
            if (dp[j-a[i]])
            {
                dp[j]=1;
                if (trace[j]==0) trace[j]=i;
                if (j>=l && j<=r)
                {
                    s=j;
                    flag=1;
                    break;
                }
            } 
        if (flag) break;
    }
    int sz=0;
    vector<int> ans;
    while (s)
    {
        sz++;
        ans.push_back(trace[s]);
        s-=a[trace[s]];
    }
    cout<<sz<<"\n";
    sort(ans.begin(),ans.end());
    for (int x : ans) cout<<x<<" ";
}
void sub4()
{
    int sz=r/a[1];
    cout<<sz<<"\n";
    FOR(i,1,sz) cout<<i<<" ";
}

void sub5()
{
    int sum_prefix=0;
    int remove_idx=-1,idx;
    FOR(i,1,n)
    {
        sum_prefix+=a[i];
        if (sum_prefix>=l && sum_prefix<=r) 
        {
            idx=i;
            break;
        }
        if (sum_prefix>r) 
        {
            idx=i;
            break;
        }
    }
    if (sum_prefix>=l && sum_prefix<=r)
    {
        cout<<idx<<"\n";
        FOR(i,1,idx) cout<<i<<" ";
    }
    else
    if (sum_prefix>r)
    {
        FOR(i,1,idx)
            if (sum_prefix-i>=l && sum_prefix-i<=r)
            {
                remove_idx=i;
                break;
            }
        cout<<idx-1<<"\n";
        FOR(i,1,idx)
            if (i!=remove_idx) cout<<i<<" ";
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>l>>r;
    FOR(i,1,n) 
    {
        cin>>a[i], sum+=a[i];
        if (a[i]!=a[1]) check_same=false;
        if (a[i]!=i) check_inc=false;
    }
    sub2();
    // if (r>1e6 && n<=20 && !have && !check_same && !check_inc) sub1(), have=true;
    // if (r>1e6 && n<=40 && !have && !check_same && !check_inc) sub2(), have=true;
    // else if (r<=1e6 && !have) sub3_sub6(), have=true;
    // else if (check_same && !have) sub4(), have=true;
    // else if (check_inc && !have) sub5(), have=true;
}
