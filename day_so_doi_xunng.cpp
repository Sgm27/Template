#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	int i=1,j=n,cnt=0;
	while (i<j)
	{
		if (a[i]==a[j]) 
		{
			i++;
			j--;
			if (i>=j) break;
		}
		else
		if (a[i]<a[j])
		{
			a[i+1]+=a[i];
			cnt++;
			i++;
		}
		else 
		{
			a[j-1]+=a[j];
			cnt++;
			j--;
		}
	}
	cout<<cnt;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
