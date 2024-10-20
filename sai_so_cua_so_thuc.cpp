#include<iostream>
using namespace std;
using ll = long long;
#define maxn 90
ll f[maxn+1];
void init()
{
    f[0]=0;
    f[1]=1;
    for (int i=2;i<=maxn;i++) f[i]=f[i-1]+f[i-2];
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int n;
    cin>>n;
    cout<<f[n];
}

