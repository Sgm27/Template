#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int n,s,x[25],a[25],sum,cnt,res;
bool used[25];
void Try(int i)
{
    for (int j=0;j<=1;j++)
        if (cnt+j<res && sum+a[i]*j<=s)
        {
            cnt+=j;
            sum+=a[i]*j;
            if (i==n)
            {
                if (sum==s) res=min(res,cnt);
            }
            else Try(i+1);
            sum-=a[i]*j;
            cnt-=j;
        }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        memset(used,false,sizeof(used));
        cnt=sum=0;
        res=1e9;
        cin>>n>>s;
        for (int i=1;i<=n;i++) cin>>a[i];
        Try(1);
        cout<<res<<endl;
    }
}

