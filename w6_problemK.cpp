#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
int n,k;
ll Try(int n,int k)
{
    if ((n+k)%2==0 && (n-k)/2>0) return Try((n+k)/2,k)+Try((n-k)/2,k);
    return 1;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    cout<<Try(n,k);
}

