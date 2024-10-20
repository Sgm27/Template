#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[105][12];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=11;j++) cin>>a[i][j];
}
void process()
{
	ll res=-1;
	for (int i=1;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
			for (int k=j+1;k<=n;k++)
			{
				ll tmp=0;
				for (int l=1;l<=11;l++)
				{
					tmp+=max(a[i][l],max(a[j][l],a[k][l]));
				}
				res=max(res,tmp);
			}
	cout<<res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
