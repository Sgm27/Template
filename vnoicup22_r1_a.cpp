#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn],b[maxn],n;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    int l1=1,l2=1;
    while (a[l1]!=b[1]) cout<<"a", l1++;
    for (int i=1;i<=n;i++) cout<<"b";
    for (int i=l1;i<=n;i++) cout<<"a"; 
}

