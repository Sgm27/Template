#include <bits/stdc++.h>
using namespace std;
int d[11],n;
void input()
{
	cin>>n;
}
void khoitao()
{
	d[0]=2; d[1]=7; d[2]=2; d[3]=3;
	d[4]=3; d[5]=4; d[6]=2; d[7]=5;
	d[8]=1; d[9]=2;
}
void process()
{
	cout<<d[n/10]*d[n%10];
}
int main()
{
	khoitao();
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
