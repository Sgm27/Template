#include <bits/stdc++.h>
using namespace std;
using fl=float;
struct mang{
	fl w,c;
};
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int res=INT_MIN;
		mang a[n+5];
		int l[n+5];
		for (int i=1;i<=n;i++) cin>>a[i].w>>a[i].c;
		for (int i=1;i<=n;i++)
		{
			l[i]=1;
			for (int j=1;j<i;j++) 
				if (a[j].w<a[i].w && a[j].c>a[i].c) l[i]=max(l[i],l[j]+1);
			res=max(res,l[i]);
		}
		cout<<res<<endl;
	}
}
