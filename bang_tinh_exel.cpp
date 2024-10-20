#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct mang{
	ll l;
	ll r;
};
mang chan[7];
void init()
{
	chan[1].l=1; chan[1].r=26;
	chan[2].l=27; chan[2].r=702;
	chan[3].l=703; chan[3].r=18278;
	chan[4].l=18279; chan[4].r=475254;
	chan[5].l=475255; chan[5].r=12356630;
	chan[6].l=12356631; chan[6].r=321272406;
}
string process(ll n)
{
	string res="";
	int chot;
	for (int i=6;i>=1;i--)
	{
		if (n>=chan[i].l && n<=chan[i].r)
		{
			chot=i;
			break;
		}
	}
	ll tmp;
	while (chot>0)
	{
		chot--;
		for (int i=26;i>=1;i--) 	
		{
			tmp=n;
			tmp-=i*pow(26,chot);
			if (tmp>=chan[chot].l && tmp<=chan[chot].r) 
			{
				res+=('A'+i-1);
				break;
			}
		}
		n=tmp;
	}
	return res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	init();
	while (1)
	{
		char tmp;
		ll n,m;
		cin>>tmp>>n>>tmp>>m;
		if (n==0 && m==0) return 0;
		cout<<process(m)<<n<<endl;
	}
}
