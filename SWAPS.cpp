#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int BLOCK_SZ = 1024;
#define maxn 500005
int n,a[maxn],q,numBlock;
vector<int> Node[maxn / BLOCK_SZ + 5];
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
void Update(int pos,int val)
{
    int CurBlock = pos / BLOCK_SZ;
    auto oldPos = lower_bound(Node[CurBlock].begin(),Node[CurBlock].end(),a[pos]);
    Node[CurBlock].erase(oldPos);
    a[pos] = val;
    auto newPos = lower_bound(Node[CurBlock].begin(),Node[CurBlock].end(),a[pos]);
    Node[CurBlock].insert(newPos,a[pos]);
}
int between(vector<int> Node,int st,int ed)
{
    return upper_bound(Node.begin(),Node.end(),ed) - lower_bound(Node.begin(),Node.end(),st);
}
pair<long long,long long> ChageINV(int index,int start,int end)
{
    pair<long long,long long> ans = {0,0};
    int CurBlock = index / BLOCK_SZ;
    // cerr<<CurBlock<<"\n";
    for (int i=0;i < CurBlock;i++)
        ans.first += between(Node[i],start+1,end);
    // cout<<start<<" "<<end<<"\n";
    for (int i=CurBlock+1;i<numBlock;i++)
        ans.second += between(Node[i],start,end-1);
    int LowId = CurBlock * BLOCK_SZ;
    int HighId = (CurBlock + 1) * BLOCK_SZ; 
    for (int i=LowId;i<index;i++)
        if (a[i] > start && a[i] <= end) ans.first++;
    for (int i=index+1;i<HighId;i++)
        if (a[i] >= start && a[i] < end) ans.second++;
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.ans","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long answer = 0;
    cin>>n;
    Fenwick fw(50005);
    FOR(i,1,n) 
    {
        cin>>a[i];
        Node[i / BLOCK_SZ].push_back(a[i]);
    }
    numBlock = n / BLOCK_SZ + 1;
    FOD(i,n,1)
    {
        answer += fw.get(a[i]-1);
        fw.update(a[i],1);
    }
    for (int i = 0; i<= n / BLOCK_SZ ;i++)
        sort(Node[i].begin(),Node[i].end());
    cin>>q;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        if (a[x] < y)
        {
            pair<long long, long long> change = ChageINV(x,a[x],y);
            answer -= change.first;
            answer += change.second;
            Update(x,y);
        }
        else
        if (a[x] > y)
        {
            pair<long long, long long> change = ChageINV(x,y,a[x]);
            answer += change.first;
            answer -= change.second;
            // cerr<<change.first<<" "<<change.second<<"\n";
            Update(x,y);
        }
        cout<<answer<<"\n";
    }
}
