#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define w first
#define v second
#define NAME "dttui1"

using namespace std;

const int N = 42;
int n, m, r, V, W, now;
ii a[N];
vector <ii> s[2];

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].v;
}

void Try(int i)
{
    if (W > m) return;
    for (int j = 0; j <= 1; j++)
    {
        if (j) 
        {
            V += a[i].v;
            W += a[i].w;
        }
        if (i == r) 
        { 
            if (W <= m) s[now].push_back({W, V}); 
        } 
        else Try(i+1);  
        if (j) 
        { 
            V -= a[i].v; 
            W -= a[i].w; 
        } 
    }
}

bool cmp(ii x, ii y)
{ 
    return x.w > y.w;
}

void solve()
{
    if(n == 1) {
        cout << (a[1].w <= m ? a[1].v : 0) << "\n";
        return;
    }
    r = n/2;
    W = 0;
    Try(1);
    now = 1;
    r = n;
    W = 0;
    Try(r/2+1);

    sort(s[0].begin(), s[0].end(), cmp);
    sort(s[1].begin(), s[1].end());
    int mx2 = 0, ans = 0, j = 0;
    for (int i = 0; i < s[0].size(); i++)
    {
        while (j< s[1].size() && s[0][i].w + s[1][j].w <= m ) mx2 = max(mx2, s[1][j].v),j++;
         ans = max(s[0][i].v+mx2, ans);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen(NAME".INP", "r"))
    {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    input();
    solve();
    return 0;
}
