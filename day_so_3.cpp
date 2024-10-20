#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
struct mang{
	int op=0,cl=0;
};
mang b[1000005];
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n>>k;
	for (int i=1;i<=n;i++) a[i]=0;
	for (int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		b[x].op++;
		b[y].cl++;
	}
	int tmp=0;
	for (int i=1;i<=n;i++)
	{
		tmp+=b[i].op;
		a[i]=tmp;
		tmp-=b[i].cl;
	}
	sort(a+1,a+1+n);
	cout<<a[n/2+1];
}
