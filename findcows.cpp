#include <bits/stdc++.h>
using namespace std;
int n,a[50005],dem,res=0;
struct mang{
	int gt,cs;
};
mang kq[50005];
void nhap()
{
	string s;
	cin>>s;
	n=s.length();
	for (int i=0;i<n;i++) 
		if (s[i]==')') a[i+1]=0;
		else a[i+1]=1;
	a[n+1]=2;
}
void process()
{
	if (n<=3) {
		cout<<"0";
		return;
	}
	int cnt=0; dem=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==a[i+1]) dem++;
		if (a[i]!=a[i+1])
		{
			if (dem>1) 
			{
				cnt++;
				kq[cnt].gt=dem;
				kq[cnt].cs=a[i];
			}
			dem=1;
		}
	}
	//for (int i=1;i<=cnt;i++) cout<<kq[i].gt<<" "<<kq[i].cs<<endl;
	int i=1;
	while (i<=cnt)
	{
		if (kq[i].cs==1) 
			for (int j=i+1;j<=cnt;j++) 
			{
				if (kq[j].cs==0) res+=((kq[i].gt-1)*(kq[j].gt-1));	
			} 
		i++;
	}
	cout<<res;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	nhap();
	process();
}
