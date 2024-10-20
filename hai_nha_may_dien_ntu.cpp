#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 400005
int n,q,cnt_R1[maxn],cnt_R2[maxn],res[maxn];
struct data{
    int r1,r2;
}   a[maxn*2];
int distance(int x,int y,int a,int b)
{
    return ceil(sqrt((x-a)*(x-a)+(y-b)*(y-b)));
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	int stt=0;
	while (cin>>n)
	{
		if (!n) return 0; 
		++stt;
		cout<<"Case "<<stt<<":\n";
		memset(cnt_R1,0,sizeof(cnt_R1));
		memset(cnt_R2,0,sizeof(cnt_R2));
		FOR(i,1,n) cin>>a[i].r1>>a[i].r2;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2>>q;
		FOR(i,1,n)
		{
			int t1=distance(a[i].r1,a[i].r2,x1,y1);
			cnt_R1[t1]++;
			int t2=distance(a[i].r1,a[i].r2,x2,y2);
			cnt_R2[t2]++;
			a[i].r1=t1, a[i].r2=t2;
		}
		FOR(i,1,maxn-5) cnt_R1[i]+=cnt_R1[i-1], cnt_R2[i]+=cnt_R2[i-1];
		FOR(i,1,q)
		{
			int R1,R2;
			cin>>R1>>R2;
			cout<<max(0ll,n-cnt_R1[R1]-cnt_R2[R2])<<"\n";
		}
	}
}
