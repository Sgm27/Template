#include<iostream>
using namespace std;
using ll = long long;
int n;
ll res=0;
pair<ll,ll> sum;
struct mang{
    int x,y;
};
mang a[100005];
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    sum.first=sum.second=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        res+=a[i].x*a[i].x+a[i].y*a[i].y;
        sum.first+=a[i].x;
        sum.second+=a[i].y;
    }
    ll tmp=0;
    for (int i=1;i<=n;i++) 
        tmp+=(a[i].x*(sum.first-a[i].x)+a[i].y*(sum.second-a[i].y));
    res=res*(n-1)-tmp;
    cout<<res;
}

