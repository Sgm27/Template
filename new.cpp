#include <bits/stdc++.h>
using namespace std;
long long s;
void input()
{
    cin>>s;
}
void process()
{
    long long sum=0;
    for (long long i=1;i<=s;i++) sum+=i;
    cout<<sum;
}
int main()
{
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    input();
    process();
}
