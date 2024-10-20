#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 1005
int a[maxn],b[maxn],n;
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
        unordered_map<int,int> D;
        cin>>n;
        vector<int> v(n*(n-1)/2);
        FOR(i,0,n*(n-1)/2-1) cin>>v[i], D[v[i]]++;
        // sort(a+1,a+1+n*(n-1)/2);
        sort(v.begin(),v.end());
        // vector<int> v(a+1,a+1+n*(n-1)/2);
        vector<int> ans;
        int sum=0,len=v.size(),idx=0,cnt_lower=n-1;
        while (1)
        {
            if (!D[v[idx]]) break;
            D[v[idx]]-=(cnt_lower);
            ans.push_back(v[idx]);
            idx+=cnt_lower;
            cnt_lower--;
        }
        ans.push_back(1e9);
        for (int x : ans) cout<<x<<" ";
        cout<<"\n";
    }
}
