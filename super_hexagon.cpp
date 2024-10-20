#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll d[181];
void khoitao()
{
	for (int i=1;i<=180;i++)
		for (int j=1;j<=5545802;j++)
			if (j*180%i==0) 
			{
				ll res=j*180/i;
				ll tmp=i/__gcd(i,180);
				if (res-tmp>=2) 
				{
					d[i]=res;
					break;
				}
				else 
				{
					d[i]=res*2;
					break;
				}
			}
	d[180]=-1;
}
int main()
{
	memset(d,-1,sizeof(d));
//	freopen("thu.inp","r",stdin);
	khoitao();
	int tc; cin>>tc;
	while (tc--)
	{
		int n;
		cin>>n;
		cout<<d[n]<<" ";
	}
}
