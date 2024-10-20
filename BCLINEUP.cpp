#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
using ll = long long;
int n,q,a[50005],Min[25][50005],Max[25][50005];
int get(int l,int r,string type)
{
	int k=log2(r-l+1);
	if (type=="max") return max(Max[k][l],Max[k][r-(1<<(k))+1]);
	else return min(Min[k][l],Min[k][r-(1<<(k))+1]);
}
void RMQ()
{
	for (int i=1;i<=n;i++) Min[0][i]=Max[0][i]=a[i];
	for (int i=1;i<=log2(n);i++)
	{
		for (int j=1;j<=(n-(1<<i)+1);j++)
		{
			Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<(i-1))]);
			Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<(i-1))]);
		}
	}
}
int main()
{
	// freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	RMQ();
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<get(l,r,"max")-get(l,r,"min")<<"\n";
	}
}

