#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
int d[maxn]={},a[maxn],n,cnt[maxn],Min[25][50005],Max[25][50005];
void make_st()
{
    int t=log2(n);
    for (int i=1;i<=t;i++)
    {
        for (int j=1;j<=n-(1<<i)+1;j++)
            {
                Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<(i-1))]);
                Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<(i-1))]);
            }  
    }
}
int get(int l,int r,string type)
{
    int k=log2(r-l+1);
    if (type=="max") return max(Max[k][l],Max[k][r-(1<<k)+1]);
    else  return min(Min[k][l],Min[k][r-(1<<k)+1]);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        Max[0][i]=a[i];
        Min[0][i]=a[i];
        d[a[i]]++;
        if (d[a[i]]==1) cnt[i]=cnt[i-1]+1;
    }
    make_st();
    int res=0;
    cout<<get(1,3,"max")<<"\n";
    for (int len=1;len<=n;len++)
        for (int i=1;i<=n-len+1;i++) 
            if (get(i,i+len-1,"max")==len && get(i,i+len-1,"min")==1 && cnt[i+len-1]-cnt[i-1]==len) res++;
    cout<<res;
}

