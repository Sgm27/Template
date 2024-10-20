#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,r,t,sum=0;
struct mang{
	ll diem,bai;
};
mang a[100005];
void input()
{
	cin>>n>>r>>t;
	t*=n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i].diem>>a[i].bai;
		sum+=a[i].diem;
	}
}
bool cmp(mang a,mang b)
{
	return a.bai<b.bai;
}
void process()
{
	sort(a+1,a+1+n,cmp);
	t-=sum;
	ll res=0,i=0;
	if (t<0) 
	{
		cout<<0;
		return;
	}
	while (t)
	{
		i++;
		res+=min(r-a[i].diem,t)*a[i].bai;
		t-=min(r-a[i].diem,t);
	}	
	cout<<res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
