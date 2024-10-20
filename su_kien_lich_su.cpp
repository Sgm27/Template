#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
using ll=long long;
int n,Max,cnt;
struct mang{
	int x,y;
};
mang a[100005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
}
bool cmp(mang a,mang b)
{
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
void process()
{
	sort(a+1,a+1+n,cmp);
    cnt=0;
	int cs=0;
	a[0].y=-1;
	for (int i=1;i<=n;i++)
	{
		if (a[i].y>a[cs].y) cs=i;
		if (a[i].x!=a[0].x && a[i].y<a[cs].y) cnt++;
	}
	cout<<cnt;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	input();
	process();
}
