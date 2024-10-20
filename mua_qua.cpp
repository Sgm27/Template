#include <iostream>
#include<algorithm>
using namespace std;
using ll = long long;
ll n,s;
struct mang{
	ll x,y;
	ll sum()
	{
		return x+y;
	}
};
mang a[1005];
void input()
{
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
}
bool cmp(mang a,mang b)
{
	if (a.sum()!=b.sum()) return a.sum()<b.sum();
	else return a.x<b.x;
}
void process()
{
	sort(a+1,a+1+n,cmp);
	ll tong=0,i=1,res=0;
	while (tong<=s)
	{
		ll tmp=a[i].sum();
		tong+=tmp;
		if (tong<=s) 
		{
			res++;
		}
		else
		{
			tong-=tmp;
			a[i].x/=2;
			tong+=a[i].sum();
			tmp=a[i].sum();
			if (tong<=s) 
			{
				res++;
				break;
			}
			else tong-=tmp;
		}
		if (i==n) break;
		else i++;
	}
	cout<<res;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	input();
	process();
}