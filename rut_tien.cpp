#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int a[5]={100,20,10,5,1};
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int s; cin>>s;
    int idx=0,res=0;
    while (s)
    {
        if (s>=a[idx]) 
        {
            s-=a[idx];
            res++;
        }
        else idx++;
    }
    cout<<res;
}

