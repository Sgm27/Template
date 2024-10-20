#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int n,s,x[25],Min=1e9,res[25],cnt=0;
void update()
{
    cnt++;
    if (x[n]-x[1]<Min)
    {
        Min=x[n]-x[1];
        for (int i=1;i<=n;i++) res[i]=x[i];
    }
}
void Try(int i)
{
    for (int j=x[i-1];j<=s-n+i;j++)
    {
        x[i]=j;
        s-=j;
        if (i==n)
        {
            if (s==0) update();
        }
        else Try(i+1);
        s+=j;
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    x[0]=1;
    Try(1);
    cout<<cnt<<"\n";
    reverse(res+1,res+1+n);
    for (int i=1;i<=n;i++) cout<<res[i]<<" ";
}

