#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1<<20
int n,a[maxn],st[20][maxn];
int get_min(int l,int r)
{
    int k=log2(r-l+1);
    return min(st[k][l],st[k][r-(1<<k)+1]);
}
void make_ST()
{
    for (int i=1;i<=log2(n);i++)
        for (int j=1;j<=(n-(1<<i)+1);j++)
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void process()
{
    make_ST();

    for (int len=1;len<=n;len++)
    {
        int ans=-1;
        for (int i=1;i<=n-len+1;i++) 
            ans=max(ans,get_min(i,i+len-1));
        cout<<ans<<" ";
    }
    cout<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>st[0][i];   	
        process();
    }
}

