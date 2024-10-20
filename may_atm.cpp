#include<iostream>
using namespace std;
using ll = long long;
int n,S,a[35],res=99999;
void input()
{
    cin>>n>>S;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void Try(int i,ll sum,int d)
{
    if (sum>S || d>res) return;
    if (i==n+1) 
    {
        if (sum==S) res=min(res,d);
        return;
    }
    Try(i+1,sum,d);
    Try(i+1,sum+a[i],d+1);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    Try(1,0,0);
    cout<<res;
}

