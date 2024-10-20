#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 400005
int n,q,fw[maxn],cnt_R1[maxn],cnt_R2[maxn],res[maxn];
struct data{
    int r1,r2,type,id;
}   a[maxn*2];
int distance(int x,int y,int a,int b)
{
    return ceil(sqrt((x-a)*(x-a)+(y-b)*(y-b)));
}
void update(int x)
{
    for(;x<=maxn-5;x+=x&-x) fw[x]++;
}
int get(int x)
{
    int ans=0;
    for(;x>0;x-=x&-x) ans+=fw[x];
    return ans;
}
bool cmp(data a,data b)
{
    if (a.r1!=b.r1) return a.r1<b.r1;
    else
    if (a.r2!=b.r2) return a.r2<b.r2;
    else 
    return a.type<b.type;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i].r1>>a[i].r2, a[i].type=0;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2>>q;
    FOR(i,1,n)
    {
        int t1=distance(a[i].r1,a[i].r2,x1,y1);
        cnt_R1[t1]++;
        int t2=distance(a[i].r1,a[i].r2,x2,y2);
        cnt_R2[t2]++;
        a[i].r1=t1, a[i].r2=t2;
    }
    FOR(i,1,maxn-5) cnt_R1[i]+=cnt_R1[i-1], cnt_R2[i]+=cnt_R2[i-1];
    FOR(i,n+1,n+q)
        cin>>a[i].r1>>a[i].r2, a[i].type=1, a[i].id=i-n;
    n+=q;
    sort(a+1,a+1+n,cmp);
    FOR(i,1,n)
    {
        if (!a[i].type)
            update(a[i].r2);
        else
            res[a[i].id]=cnt_R1[a[i].r1]+cnt_R2[a[i].r2]-get(a[i].r2);
    }
    FOR(i,1,q) cout<<res[i]<<"\n";
}
