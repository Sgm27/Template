#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
void process()
{
    int base=n/7*2;
    int mod=n%7;
    int Max,Min;
    Max=Min=base;
    if (mod<=2) Max+=mod;
    else Max+=2;
    if (mod==6) Min++;
    cout<<Min<<" "<<Max;   
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    process();
}

