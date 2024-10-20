#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
struct mang{
	int cs1,cs2;
};
vector<mang> res;
bool cmp(mang a,mang b)
{
	if (a.cs1!=b.cs1) return a.cs1<b.cs1;
	else return a.cs2<b.cs2;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>a>>b>>c>>d;
	for (int i=d;i<=b;i++)
		for (int j=max(i+1,c);j<=a;j++) 
		{
			mang k;
			k.cs1=j; k.cs2=i;
			res.push_back(k);
		}
	sort(res.begin(),res.end(),cmp);
	cout<<res.size()<<endl;
	for (mang k : res)
	{
		cout<<k.cs1<<" "<<k.cs2<<endl;
	}
}
