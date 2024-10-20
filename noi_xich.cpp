#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 20005
int n,a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int l=1,r=n,res=0;
    while (l<r)
    {
        if (a[l])
        {
            res++;
            r--;
            a[l]--;
        }
        else l++;
    }
    cout<<res;
}

