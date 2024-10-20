#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,a[maxn],k,Max;
bool f(int x)
{
    int pre_val=a[1],kk=k-1,pre_pos=1;
    while (kk)
    {
        auto it=lower_bound(a+pre_pos,a+1+n,pre_val+x);
        if (it==a+1+n) return false;
        else
        {
            pre_val=*it;
            pre_pos=it-a;
            kk--;
        }
    }
    return true;
}
void process()
{
    int l=0,r=Max+1;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (f(m)) l=m;
        else r=m;
    }
    cout<<l<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i], Max=max(Max,a[i]);
        sort(a+1,a+1+n);
        process();   
    }
}

