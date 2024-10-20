#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
ll prime[maxn],n,ans[maxn];
pair<ll,int> a[maxn];
void sang(ll l,ll r)
{
    // for (int i=0;i<=r-l;i++) prime[i]=1+(l+i);
	for (ll i=1;i<=sqrt(r);i++)
		for (ll j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
		{
            if (i==j/i) prime[j-l]+=i;
            else prime[j-l]+=i+j/i;
        }
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
    sang(a[1].first,a[1].first+1000000);
    for (int i=1;i<=n;i++) 
        ans[a[i].second]=prime[a[i].first-a[1].first];
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

