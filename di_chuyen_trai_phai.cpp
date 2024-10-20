#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("thu.inp","r",stdin);
	string s;
	cin>>s;
	int left=0,right=0,res=0;
	for (char x : s)
	{
		if (x=='R')
		{
			right++;
			left--;
		}
		else
		if (x=='L')
		{
			right--;
			left++;
		}
		else 
		{
			right++;
			left++;
		}
		res=max(res,max(left,right));
	}
	cout<<res;
}
