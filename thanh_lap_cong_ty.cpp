#include<iostream>
#include<math.h>
#include<set>
using namespace std;
using ll = long long;
#define maxn 100005 
int n,q,a[maxn],st_max[25][maxn],st_min[25][maxn],cnt[maxn],d[maxn*10],Max[maxn];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>st_max[0][i];
        Max[i]=max(Max[i-1],st_max[0][i]);
        cnt[i]=cnt[i-1];
        if (!d[st_max[0][i]]) 
        {
            d[st_max[0][i]]=1;
            cnt[i]++;
        }
        st_min[0][i]=st_max[0][i];
    }
}
void make_st()
{
    int t=log2(n);
    for (int i=1;i<=t;i++)
    {
        for (int j=1;j<=n-(1<<i)+1;j++)
            {
                st_max[i][j]=max(st_max[i-1][j],st_max[i-1][j+(1<<(i-1))]);
                st_min[i][j]=min(st_min[i-1][j],st_min[i-1][j+(1<<(i-1))]);
            }
    }
}
int get(int l,int r,string type)
{
    int k=log2(r-l+1);
    if (type=="max") return max(st_max[k][l],st_max[k][r-(1<<k)+1]);
    else return min(st_min[k][l],st_min[k][r-(1<<k)+1]);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    int res=0;
    // cout<<get(1,2,"min")<<"\n";
    // for (int i=1;i<=n;i++) cout<<Max[i]<<" ";
    if (st_max[0][1]==1)
    {
        res=0;
        for (int len=1;len<=n;len++)
        if (Max[len]==len && cnt[len]==len)
            {
                 res++;
            //   cout<<1<<" "<<len<<"\n";
            }
        cout<<res;
        return 0;
    }
    make_st();
    for (int len=1;len<=n;len++)
        for (int i=1;i<=n-len+1;i++) 
            if (get(i,i+len-1,"max")==len && get(i,i+len-1,"min")==1 && cnt[i+len-1]-cnt[i-1]==len)
            {
                 res++;
                //  cout<<i<<" "<<i+len-1<<"\n";
            }
    cout<<res;
}

