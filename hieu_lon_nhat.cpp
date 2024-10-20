#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,k,a[maxn],st[18][maxn];
int get(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[k][l],st[k][r-(1<<k)+1]);
}
void make_ST()
{
    for (int i=1;i<=n;i++) st[0][i]=a[i];
    for (int i=1;i<=log2(n);i++)
        for (int j=1;j<=n-(1<<i)+1;j++)
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    n--;
    for (int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
    int len=n-k;
    make_ST();
    int ans=1e9;
    for (int i=1;i<=n-len+1;i++) 
    {
        ans=min(ans,get(i,i+len-1));
    }
    cout<<ans;
}

