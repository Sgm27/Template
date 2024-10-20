#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[5];
int main()
{
//	freopen("thu.inp","r",stdin);
	while (cin>>a[1]>>a[2]>>a[3]>>a[4])
	{
		if (!a[1] && !a[2] && !a[3] && !a[4]) return 0;
		ll res=0;
		while (1)
		{
			if (a[1]==a[2] && a[2]==a[3] && a[3]==a[4]) 
			{
				cout<<res<<endl;
				break;
			}
			else 
			{
				res++;
				ll tmp1=abs(a[2]-a[1]);
				ll tmp2=abs(a[3]-a[2]);
				ll tmp3=abs(a[4]-a[3]);
				ll tmp4=abs(a[1]-a[4]);
				a[1]=tmp1; a[2]=tmp2; a[3]=tmp3; a[4]=tmp4;
			}
		}
	}
}
