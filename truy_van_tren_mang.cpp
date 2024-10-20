#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int a[1000015];
int main()
{
	// freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	a[0]=-1;
	a[n+1]=1e9+15;
	sort(a,a+2+n);
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		int it1=lower_bound(a,a+2+n,l)-a;
		int it2=upper_bound(a,a+2+n,r)-a-1;
		cout<<max(0,it2-it1+1)<<endl;
	}
}

