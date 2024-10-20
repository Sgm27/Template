#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 

int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<(n/4096)*4+(n%4096!=0)*4;
}

