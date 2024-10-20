#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
#define maxq 200005
int n,t[maxn],ans[maxq];
pair<int,int> a[maxn];
struct query{
    int l,r,k,id;
};
query Q[maxq];
bool cmp(query a,query b)
{
    return a.k<b.k;
}
void update(int x,int val)
{
    while (x<=n)
    {
        t[x]+=val;
        x+=(x&(-x));
    }
}
int get(int x)
{
    int sum=0;
    while (x>0)
    {
        sum+=t[x];
        x-=(x&(-x));
    }
    return sum;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    int q;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>Q[i].l>>Q[i].r>>Q[i].k;
        Q[i].id=i;
    }
    sort(Q+1,Q+1+q,cmp);
    // for (int i=1;i<=n;i++) cout<<a[i].first<<" "<<a[i].second<<"\n";
    int idx=n;
    for (int i=q;i>=1;i--)
    {
        while (a[idx].first>Q[i].k) 
        {
            update(a[idx].second,1);
            idx--;
        }
        ans[Q[i].id]=get(Q[i].r)-get(Q[i].l-1);
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}

