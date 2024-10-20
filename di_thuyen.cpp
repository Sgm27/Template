#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,a[15],res=1e9,sum[5],dem[5],ma,mi;
void input()
{
    n=12;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=4;i++) 
    {
        sum[i]=0;
        dem[i]=0;
    }
}
void Try(int i)
{
    for (int j=1;j<=4;j++)
        if (dem[j]<3)
    {
        sum[j]+=a[i];
        dem[j]++;
        if (i==n)
        {
            int Max=max(sum[1],max(sum[2],max(sum[3],sum[4])));
            int Min=min(sum[1],min(sum[2],min(sum[3],sum[4])));
            if (res>Max-Min)
            {
                res=Max-Min;
                ma=Max;
                mi=Min;
            }
        }
        else Try(i+1);
        dem[j]--;
        sum[j]-=a[i];
    }
}
int main()
{
   // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();    
    Try(1);
    cout<<res;
}

