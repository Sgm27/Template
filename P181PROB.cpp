#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct mang{
//	bool xh=false;
	ll hs1,hs2;
};
map<pair<ll,ll>,mang> mp;
ll n,a[1005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
}
void process()
{
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		{
			ll tmp1=a[j]-a[i];
			ll tmp2=j-i;
			ll tmp=__gcd(tmp1,tmp2);
			if (!mp.count({tmp1/tmp,tmp2/tmp})) 
			{
			//	mp[{tmp1/tmp,tmp2/tmp}].xh=true;
				mp[{tmp1/tmp,tmp2/tmp}].hs1=i;
				mp[{tmp1/tmp,tmp2/tmp}].hs2=j;
				mp[{-tmp1/tmp,tmp2/tmp}].hs1=i;
				mp[{-tmp1/tmp,tmp2/tmp}].hs2=j;
				mp[{tmp1/tmp,-tmp2/tmp}].hs1=i;
				mp[{tmp1/tmp,-tmp2/tmp}].hs2=j;
			}
			else 
			if (mp[{tmp1/tmp,tmp2/tmp}].hs1!=i && mp[{tmp1/tmp,tmp2/tmp}].hs2!=j && mp[{tmp1/tmp,tmp2/tmp}].hs2!=i && mp[{tmp1/tmp,tmp2/tmp}].hs1!=j)
			{
				// cout<<mp[{tmp1/tmp,tmp2/tmp}].hs1<<" "<<mp[{tmp1/tmp,tmp2/tmp}].hs2<<" "<<i<<" "<<j<<endl;
				cout<<"yes";
				return;
			}
		}
	cout<<"no";
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
