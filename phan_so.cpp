#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[12],b[12],kq[100000];
float khoiphuc(ll a[],ll n)
{
	float res=a[n];
	for (int i=n;i>=3;i--)
	{
		res=a[i-1]+(float)(1/res);
	}
	res=1/res;
	res+=a[1];
	return (res);
}
void phantich(float st)
{
	float s=st;
	if (s==(ll)s) 
	{
		cout<<s<<endl;
		return;
	}
	ll i=1;
	if (s<0) 
	{
		kq[i]=-(ll)(abs(ll(s))+1);
		s+=(float)(abs(ll(s))+1);	
	} 
	else 
	{
		kq[i]=ll(s);
		s-=(float)((ll)(s));
	}
	string tmp=to_string(s);
	tmp.erase(tmp.begin(),tmp.begin()+2);
	ll n=tmp.length();
	while (tmp[n]=='0') n--;
	ll res=stoll(tmp);
	ll x=pow(10,n);
	ll t=__gcd(res,x);
	ll tmp1=x/t,tmp2=res/t;
	bool ok=true;
	while (ok)
	{
		i++;
		ll tam=tmp2;
		kq[i]=(ll)(tmp1/tmp2);
		tmp2=tmp1%tmp2;
		tmp1=tam;
		if (tmp2==0) ok=false;
	}
	for (int j=1;j<=i;j++) cout<<kq[j]<<" ";
	cout<<endl;
}
void process(ll a[],ll n,ll b[],ll m)
{
	float res1=khoiphuc(a,n);
	float res2=khoiphuc(b,m);
	phantich((float)(res1+res2));
	phantich((float)(res1-res2));
	phantich((float)(res1*res2));
	cout<<(float)(res1/res2);
//	phantich((float)(res1/res2));
}
int main()
{
	freopen("thu.inp","r",stdin);
	ll n,m;
	while (cin>>n>>m)
	{
		if (n==0 && m==0) return 0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=m;i++) cin>>b[i];
		process(a,n,b,m);
	}
}
