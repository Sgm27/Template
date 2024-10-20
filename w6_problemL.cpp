#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int cnt=0;
int Try(int x,int y)
{
    // cout<<x<<" "<<y<<"\n";
    if (x==y) return 0;
    if (x-y>y) return 1;
    return Try(y,x-y)+1;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (1)
    {
        int x,y;
        cin>>x>>y;
        if (!x && !y) return 0;
        if (x<y) swap(x,y);
        if (Try(x,y)%2) cout<<"T\n";
        else cout<<"S\n";
    }
}

