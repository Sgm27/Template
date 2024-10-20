#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,a[maxn],q;
struct Fenwick{
    vector<int> t,pos;
    int n;
    void init(int sz)
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
} fw[maxn];

int find_pos(int idx,int val)
{
    return lower_bound(fw[idx].pos.begin(),fw[idx].pos.end(),val) - fw[idx].pos.begin() + 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) 
    {
        cin>>a[i];
        fw[a[i]].pos.push_back(i);
    }
    FOR(i,1,n) 
    {
        fw[i].init(fw[i].pos.size() + 5);
        for (int x : fw[i].pos) fw[i].update(find_pos(i,x),x*x);
    }
    int last = 0;
    while (q--)
    {
        int type; cin>>type;
        if (type == 1)
        {
            int p; cin>>p;
            p = (p + last - 1) % (n - 1) + 1;
            if (a[p] == a[p+1]) continue;
            int pos1 = find_pos(a[p],p);
            int pos2 = find_pos(a[p+1],p+1);
            fw[a[p]].update(pos1,-p * p + (p+1) * (p+1));
            fw[a[p+1]].update(pos2,-(p+1) * (p+1) + p * p);
            fw[a[p]].pos[pos1-1] = p+1;
            fw[a[p+1]].pos[pos2-1] = p;
            swap(a[p],a[p+1]);
        }
        else
        {
            int l,r,x; 
            cin>>l>>r>>x;
            l = (l + last - 1) % n + 1;
            r = (r + last - 1) % n + 1;
            x = (x + last - 1) % n + 1;
            if (l > r) swap(l,r);
            if (type == 2)
            {
                int posL = lower_bound(fw[x].pos.begin(),fw[x].pos.end(),l) - fw[x].pos.begin() + 1;
                int posR = upper_bound(fw[x].pos.begin(),fw[x].pos.end(),r) - fw[x].pos.begin();
                if (posR == 0)
                {
                    last = 0;
                    cout<<last<<"\n";
                    continue;
                }
                last = fw[x].get(posR) - fw[x].get(posL - 1);
                cout<<last<<"\n";
            }
            else
            {
                last = fw[x].get(r) - fw[x].get(l-1);
                cout<<last<<"\n";
            }
        }
    }
}
