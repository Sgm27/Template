#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
using ll = long long;
int n,x,y,z;
void input()
{
    cin>>n>>x>>y>>z;
}
void process()
{
    x%=z;
    int tmp=x;
    for (int i=1;i<=n;i++)
    {
        tmp=(tmp+y)%z;
        if (tmp==x) 
        {
            cout<<i;
            return;
        }
    }
    cout<<n;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

