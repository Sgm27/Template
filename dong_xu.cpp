#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
ll n,Pow[80];
void build_pow()
{
    Pow[0]=1;
    for (int i=1;i<=61;i++) Pow[i]=Pow[i-1]*2;
}
void process(ll n)
{
    do
    {
        if (n%2) 
        {
            n/=2;
            continue;
        }
        else
        {
            int idx;
            for (int i=log2(n);i>=1;i--) 
                if (n%Pow[i]==0) 
                {
                    idx=i;
                    break;
                }
            n/=Pow[idx];
            n+=idx;
        }
    } while (n>=10);
    if (n%2) cout<<"n\n";
    else cout<<"y\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    int tc; cin>>tc;
    build_pow();
    while (tc--)
    {
        cin>>n;
        process(n);
    }
}

