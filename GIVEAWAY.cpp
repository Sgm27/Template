#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int BLOCK_SZ = 502;
#define maxn 500005
int n,q,a[maxn];
vector<int> node[maxn / BLOCK_SZ + 2];
void Update(int pos,int val)
{
    int CurBlock=pos / BLOCK_SZ;
    auto oldPos = lower_bound(node[CurBlock].begin(),node[CurBlock].end(),a[pos]);
    node[CurBlock].erase(oldPos);
    a[pos] = val;
    auto newPos = lower_bound(node[CurBlock].begin(),node[CurBlock].end(),a[pos]);
    node[CurBlock].insert(newPos,a[pos]); 
}
void Query(int l,int r,int val)
{
    int answer=0;
    int L = l / BLOCK_SZ + 1 , R = r / BLOCK_SZ - 1;
    for (int i=L; i<=R ; i++)
        answer += (node[i].size() - (lower_bound(node[i].begin(),node[i].end(),val) - node[i].begin()));
    if (l/BLOCK_SZ != r/BLOCK_SZ)
    {
        for (int i=l;i<L*BLOCK_SZ;i++) answer += (a[i] >= val);
        for (int i=(R+1)*BLOCK_SZ;i<=r;i++) answer += (a[i] >= val);
    }
    else
        for (int i=l;i<=r;i++) answer += (a[i] >= val);
    cout<<answer<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) 
    {
        cin>>a[i];
        node[i / BLOCK_SZ].push_back(a[i]);
    }
    for (int i=0; i<= n / BLOCK_SZ ;i++) 
        sort(node[i].begin(),node[i].end());
    cin>>q;
    while (q--)
    {
        int type; cin>>type;
        if (type == 0)
        {
            int l,r,val;
            cin>>l>>r>>val;
            Query(l,r,val);
        }
        else
        {
            int p,val;
            cin>>p>>val;
            Update(p,val);
        }
    }
}
