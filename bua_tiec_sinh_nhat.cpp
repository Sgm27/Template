#include <bits/stdc++.h>
using namespace std;
using db=long double;
db a[7],res;
const db dt=((db)sqrt(3.0)*0.25);
const db Sin=((db)sqrt(3.0)*0.5);
const db Cos=(-0.5);
const db eps=1e-12;
void input()
{
	for (int i=1;i<=6;i++) cin>>a[i];
}
void process()
{
	res=(db)((0.5)*Sin*(a[1]*a[2]+a[3]*a[4]+a[5]*a[6]))-eps;
	db ca=sqrt(a[1]*a[1]+a[2]*a[2]-2*a[1]*a[2]*Cos)-eps;
	db cb=sqrt(a[3]*a[3]+a[4]*a[4]-2*a[3]*a[4]*Cos)-eps;
	db cc=sqrt(a[5]*a[5]+a[6]*a[6]-2*a[5]*a[6]*Cos)-eps;
	db p=(db)((ca+cb+cc)*0.5);
	res+=(db)sqrt(p*(p-ca)*(p-cb)*(p-cc));
	cout<<fixed<<setprecision(0)<<(res)/dt;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	input();
	process();
}
