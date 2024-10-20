#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100000
bool check[maxn+5];
int n,a[maxn+5];
int main()
{
    memset(check,false,sizeof(check));
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        check[a[i]]=true;
    }
    int cnt=0;
    for (int i=1;i<=maxn;i++)
    {
        int tmp=0;
        for (int j=i;j<=maxn;j+=i) 
            if (check[j]) tmp=__gcd(tmp,j);
        if (tmp==i) cnt++;
    }
    cout<<cnt;
}

