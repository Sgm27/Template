#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn
const int N=1e5; 
vector<int> nt;
int prime[N];
void sang()
{
    for (int i=1;i<=N;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i=2;i<=sqrt(N);i++)
        if (prime[i])
            for (int j=i*i;j<=N;j+=i) prime[j]=0;
    for (int i=2;i<=N;i++) 
        if (prime[i]) nt.push_back(i);
}
void process(int d)
{
    ll res=1;
    int tmp=*lower_bound(nt.begin(),nt.end(),1+d);
    res=tmp*(*lower_bound(nt.begin(),nt.end(),tmp+d));
    cout<<min(res,1ll*(d+1)*(d+1)*(d+1))<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    sang();
    int tc; cin>>tc;
    while (tc--)
    {
        int d;
        cin>>d;
        process(d);	
    }
}

