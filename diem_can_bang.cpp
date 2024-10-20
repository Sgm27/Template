#include <bits/stdc++.h>
using namespace std;
using db=double;
int n,tt=0;
struct mang{
	db x,y,m;
};
mang a[100005];
void process()
{
	cout<<"Case "<<tt<<": ";
	db sum=0;
	for (int i=1;i<=n;i++) sum+=a[i].m;
	db res=0;
	for (int i=1;i<=n;i++) res+=a[i].x*a[i].m;
	res/=sum;
	cout<<fixed<<setprecision(2)<<res<<" ";
	res=0;
	for (int i=1;i<=n;i++) res+=a[i].y*a[i].m;
	res/=sum;
	cout<<fixed<<setprecision(2)<<res<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	while (cin>>n)
	{
		if (n<0) return 0;
		tt++;
		for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].m;
		process();
	}
}
