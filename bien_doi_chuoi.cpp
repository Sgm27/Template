#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int n,fA[1000005],fB[1000005];
void input()
{
    cin>>n;
    cin>>s;
}
void process()
{
    s="#"+s;
    fA[0]=fB[0]=0;
    for (int i=1;i<=n;i++)
        if (s[i]=='A') 
        {
            fA[i]=min(fA[i-1],fB[i-1]+1);
            fB[i]=min(fA[i-1]+1,fB[i-1]+1);
        }
        else
        {
            fA[i]=min(fA[i-1]+1,fB[i-1]+1);
            fB[i]=min(fB[i-1],fA[i-1]+1);
        }
    // for (int i=1;i<=n;i++) cout<<fA[i]<<" "<<fB[i]<<endl;
    cout<<min(fA[n],fB[n]+1);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

