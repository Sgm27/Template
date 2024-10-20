#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[5],cnt,x[10]; 
bool d[5];
ll res,tmp,n,kq;
void thu(int i)
{
	for (int j=x[i-1];j<=4;j++)
		if (d[j])
	{
		x[i]=j;
		d[j]=false;
		tmp*=a[j];
		if (i==cnt) 
		{
			res+=n/tmp;
		}
		else thu(i+1);
		d[j]=true;
		tmp/=a[j];
	}
}
void process(int a[],ll n)
{
	x[0]=0;
	cnt=1; kq=n;
	while (cnt<=5)
	{
		tmp=1;
		res=0;
		for (int i=0;i<=4;i++) d[i]=true;
		thu(1);
		if (cnt%2) kq-=res;
		else kq+=res;
		cnt++;
	}
	cout<<kq<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
//	freopen("thu.out","w",stdout);
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>n;
		for (int i=0;i<=4;i++) cin>>a[i];
		process(a,n);
	}
}
