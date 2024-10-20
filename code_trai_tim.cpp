#include <bits/stdc++.h>
using namespace std;
char a[15];
void prints(int l1,int r1,int l2,int r2)
{
	for (int i=l1;i<=r1;i++) a[i]='*';
	for (int i=l2;i<=r2;i++) a[i]='*';
	for (int i=1;i<=11;i++) cout<<a[i];
	cout<<endl;
	for (int i=1;i<=15;i++) a[i]=' ';
}
void process()
{
	int kt=3;
	int cnt=1;
	while (cnt<=8)
	{
		if (cnt==1) prints(2,4,8,10);
		if (cnt==2) prints(1,5,7,11);
		if (cnt==3) prints(1,6,6,11);
		if (cnt==4) prints(2,6,6,10);
		if (cnt==5) prints(3,6,6,9);
		if (cnt==6) prints(4,6,6,8);
		if (cnt==7) prints(5,6,6,7);
		if (cnt==8) prints(6,6,6,6);
		cnt++;
	}
}
int main()
{
	process();
}
