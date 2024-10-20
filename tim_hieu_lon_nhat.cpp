#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,a[100005];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
    int Max,Min,res=INT_MIN;
    Max=Min=a[1];
    for (int i=2;i<=n;i++)
        if (a[i]<Min) 
        {
            Min=a[i];
            Max=a[i];
        }
    else
    {
        Max=max(Max,a[i]);
        res=max(res,Max-Min);
    }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

