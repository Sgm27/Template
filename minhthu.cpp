#include <bits/stdc++.h>
using namespace std;
int n;
void input()
{
    cin>>n;
}
bool nto(int k)
{
    if (k==2 || k==3 ) return true;
    if (k<2 || k%2==0 || k%3==0) return false;
    int i=5;
    while (i<(int)(sqrt(k)))
    {
        if (k%i==0 || k%(i+2)==0) return false;
        else i+=6;
    }
    return true;
}
int main()
{
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    input();
    if (nto(n)) cout<<"YES"; else cout<<"NO";
}
