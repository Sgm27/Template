#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,k,a[maxn],b[maxn],Max;
bool f(int x)
{
    int kk=k;
    for (int i=1;i<n;i++)
        if (b[i]>x) 
        {
            kk-=(b[i]/x-(b[i]%x==0));
            if (kk<0) return false;
        }
    return true;
}
void process()
{
    int l=0,r=Max;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (f(m)) r=m;
        else l=m;
    }
    cout<<r<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        Max=0;
        cin>>n>>k;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if (i!=1) b[i-1]=a[i]-a[i-1];
            Max=max(Max,b[i-1]);
        }   	
        process();
    }
}

