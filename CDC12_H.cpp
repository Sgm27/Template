#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,q,bit1[maxn],bit2[maxn];
void up_point(int fw[],int x,int val)
{
    for (;x<=n;x+=x&-x) fw[x]+=val;
}
void up_range(int l,int r,int val)
{
    up_point(bit1,l,(n-l+1)*val);
    up_point(bit1,r+1,-(n-r)*val);
    up_point(bit2,l,val);
    up_point(bit2,r+1,-val);
}
int getSum(int fw[],int x)
{
    int ans=0;
    for(;x>0;x-=x&-x) ans+=fw[x];
    return ans;
}
int prefixSum(int x)
{
    return getSum(bit1,x)-getSum(bit2,x)*(n-x);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
	int ntest=0;
    while (tc-- && ++ntest)
    {
        cout<<"Scenario #"<<ntest<<":\n";
        cin>>n>>q;
        FOR(i,1,n) bit1[i]=bit2[i]=0;
        while (q--)
        {
            string type;
			int l,r;
			cin>>type>>l>>r;
			if (type=="answer") 
				cout<<prefixSum(r)-prefixSum(l-1)<<"\n";
			else
            {
				up_range(l,r,1);
                cout<<"OK\n";
            }
        } 	
    }
}
