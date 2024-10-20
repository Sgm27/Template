#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
const int N=600;
int prime[N],a[500],nmax=0;
int n,p,s,st,ed,sum,x[105];
void sang()
{
    prime[0]=prime[1]=0;
    for (int i=2;i<=N;i++) prime[i]=1;
    for (int i=2;i<=sqrt(N);i++)
        if (prime[i])
            for (int j=i*i;j<=N;j+=i) prime[j]=0;
    for (int i=2;i<=N;i++)
        if (prime[i]) a[++nmax]=i;
}
void in()
{
    for (int i=1;i<=n;i++) cout<<a[x[i]]<<" ";
    cout<<"\n";
}
void Try(int i)
{
    for (int j=x[i-1]+1;j<=ed-(n-i);j++)
        if (sum+a[j]<=s)
        {
            x[i]=j;
            sum+=a[j];
            if (i==n)
            {
                if (sum==s) in();
            }
            else Try(i+1);
            sum-=a[j];
        }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    sang();
    int tc; cin>>tc;
    for (int stt=1;stt<=tc;stt++)
    {
        cout<<"Test "<<stt<<":\n";
        cin>>n>>p>>s;
        st=upper_bound(a+1,a+1+nmax,p)-a;
        ed=upper_bound(a+1,a+1+nmax,s)-a-1;
        sum=0;
        x[0]=st-1;
        Try(1);
    }
}

