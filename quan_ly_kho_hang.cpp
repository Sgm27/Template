#include <bits/stdc++.h>
using namespace std;
int n,i=0;
map<string,int> mp;
struct mang{
	string ma,ten,hang,donvi;
	string goc,ban,lai;
};
mang a[1005];
void input()
{
	cin>>n;
	cin.ignore();
	while (n--)
	{
		i++;
		string ten;
		getline(cin,ten);
		a[i].ten=ten;
		mp[ten]++;
		stringstream ss(ten);
		string token;
		string ma1="";
		while (ss >> token)
		{
			ma1+=toupper(token[0]);
		}
		string ma2=to_string(mp[ten]);
		while (ma2.size()<4) ma2="0"+ma2;
		a[i].ma=ma1+ma2;
		cin>>a[i].hang>>a[i].donvi;
		cin.ignore();
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	for (int i=1;i<=n;i++)
		cout<<a[i].ma<<" "<<a[i].ten<<" "<<a[i].hang<<" "<<a[i].donvi<<endl;
}
