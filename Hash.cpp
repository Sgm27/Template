#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
const int base=31;
const ll MOD=1e9+7;
ll Pow[maxn],HashS[maxn],HashT;
// get HashS
ll getHash(int l,int r)
{
    return (HashS[r]-HashS[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int lenS=s.length(),lenT=t.length();
    s=" "+s;
    t=" "+t;
    // build POW
    Pow[0]=1;
    for (int i=1;i<=lenS;i++)
        Pow[i]=(Pow[i-1]*base)%MOD;
    // build HashS
    for (int i=1;i<=lenS;i++)
        HashS[i]=(HashS[i-1]*base+s[i]-'a'+1)%MOD;
    // get hashT
    for (int i=1;i<=lenT;i++)
        HashT=(HashT*base+t[i]-'a'+1)%MOD;
    for (int i=1;i<=lenS-lenT+1;i++)
        if (HashT==getHash(i,i+lenT-1)) cout<<i<<" ";
}

