#include<iostream>
using namespace std;
using ll = long long;
int n,k;
void process()
{
    if (n==1 && k==1) 
    {
        cout<<"a";
        return;
    }
    if (k>n || k==1) 
    {
        cout<<"-1";
        return;
    }
    for (int i=1;i<=n-(k-2);i++)
        if (i%2) cout<<"a";
        else cout<<"b";
    for (int i=1;i<=k-2;i++) cout<<(char)('b'+i);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    process();
}

