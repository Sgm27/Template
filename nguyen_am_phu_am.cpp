#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int nguyen(char x)
{
    if (x=='u' || x=='e' || x=='o' || x=='a' || x=='i') return 1;
    return 0;
}
void process()
{
    int ng=0,ph=0,res=0;
    for (char x : s)
    {
        if (nguyen(x)) ng++;
        else ph++;
        if (ng>)
    }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    process();
}

