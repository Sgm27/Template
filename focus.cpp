#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
struct query{
    int type,l,r,val;
    // + 1
    // - -1
    // ? 0
};
vector<query> Q;
int n;
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.resize(n+1);
    }
    void update(int x,int val)
    {
        for (;x<=n;x+=x&-x) t[x]+=val;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
};
vector<int> com;
int find_pos(int val)
{
    return lower_bound(com.begin(),com.end(),val) - com.begin() + 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    Fenwick fw(200005);
    FOR(i,1,n)
    {
        string t; cin>>t;
        if (t == "?")
        {
            int l,r,val;
            cin>>val>>l>>r;
            Q.push_back({0,l,r,val});
            com.push_back(val);
            com.push_back(l);
            com.push_back(r);
        }
        else
        {
            int val; cin>>val;
            if (t == "+") Q.push_back({1,0,0,val});
            else
                Q.push_back({-1,0,0,val});
            com.push_back(val);
        }
    }
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end()) - com.begin());
    for (query x : Q)
    {
        int type = x.type, l = x.l, r = x.r, val = x.val;
        if (type)
            fw.update(find_pos(val),type);
        else
        {
            l = find_pos(l);
            r = find_pos(r);
            int num = fw.get(r) - fw.get(l-1);
            if (num < val) 
            {
                cout<<"0\n";
                continue;
            }
            val += fw.get(l-1);
            while (r-l > 1)
            {
                int m = l+r >> 1;
                if (fw.get(m) >= val) r = m;
                else l = m;
            }
            if (fw.get(l) < val) l++;
            cout<<com[l-1]<<"\n";
        }
    }
}
