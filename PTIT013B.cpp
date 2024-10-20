#include <bits/stdc++.h>
using namespace std;
int n,cs1,cs2;
string s1,s2;
map<string,int> mp;
struct mang{
	string ten;
	int ds;
};
mang a[25],tmp[25];
bool cmp(mang a, mang b)
{
	if (a.ds!=b.ds) return a.ds>b.ds;
	else return a.ten<b.ten;
}
void process()
{	
	
	//thang
	a[cs1].ds+=3;
	for (int i=1;i<=n;i++) 
	{
		tmp[i].ten=a[i].ten;
		tmp[i].ds=a[i].ds;
	}
	sort(tmp+1,tmp+1+n,cmp);
	for (int i=1;i<=n;i++)
		if (tmp[i].ten==s1)
		{
			cout<<i<<" ";
			break;
		}
	a[cs1].ds-=3;
	// thua
	a[cs2].ds+=3;
	for (int i=1;i<=n;i++) 
	{
		tmp[i].ten=a[i].ten;
		tmp[i].ds=a[i].ds;
	}
	sort(tmp+1,tmp+1+n,cmp);
	for (int i=1;i<=n;i++)
		if (tmp[i].ten==s1)
		{
			cout<<i<<" ";
			break;
		}
	a[cs2].ds-=3;
	// hoa
	a[cs1].ds++;
	a[cs2].ds++;
	for (int i=1;i<=n;i++) 
	{
		tmp[i].ten=a[i].ten;
		tmp[i].ds=a[i].ds;
	}
	sort(tmp+1,tmp+1+n,cmp);
	for (int i=1;i<=n;i++)
		if (tmp[i].ten==s1)
		{
			cout<<i<<endl;
			break;
		}
	a[cs1].ds--;
	a[cs2].ds--;
}
int main()
{
	int dem;
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>n;
		cin>>s1>>s2;
		for (int i=1;i<=n;i++) 
		{
			cin>>a[i].ten>>a[i].ds;
			if (a[i].ten==s1) cs1=i;
			if (a[i].ten==s2) cs2=i;
		}
		process();
	}
}
