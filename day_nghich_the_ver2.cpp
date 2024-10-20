#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn],n,b[maxn];
ll T[maxn];
pair<ll,int> tmp[maxn];
void init()
{
    // roi rac hoa
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>tmp[i].first;
        tmp[i].second=i;
    }
    sort(tmp+1,tmp+1+n);
    ll last=1e9+7,cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (tmp[i].first!=last)
        {
            cnt++;
            last=tmp[i].first;
        }
        a[tmp[i].second]=cnt;
    }
}
void Update(int x,int val)
{
    while (x<=maxn)
    {
        T[x]+=val;
        x+=(x&(-x));
    }
}
ll Get(int x)
{
    ll ans=0;
    while (x>0)
    {
        ans+=T[x];
        x-=(x&(-x));
    }
    return ans;
}
void process()
{
    ll res=0;
    for (int i=n;i>=1;i--)
    {
        Update(a[i],1);
        res+=Get(a[i]-1);
    }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    process();
}

