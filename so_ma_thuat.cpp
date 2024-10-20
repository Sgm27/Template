#include <bits/stdc++.h>
using namespace std;
string a[3]={"1","14","144"};
string tmp,s="";
bool ok=false;
void nhap()
{
	cin>>tmp;
}
void thu(int i)
{
	for (int j=0;j<=2;j++)
		if (i<=9)
	{
		s+=a[j];
		if (s==tmp) 
		{
			ok=true;
			return;
		}
		else thu(i+1);
		s.erase(s.end()-a[j].length(),s.end());
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	nhap();
	thu(1);
	if (ok) cout<<"YES"; else cout<<"NO";
}
