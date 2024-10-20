#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1005;
int prime[N],r[N],d[1005],stt;
vector<int> nt;
void sang()
{
    for (int i=0;i<=N;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i=2;i<=sqrt(N);i++)
        if (prime[i])
        {
            for (int j=i*i;j<=N;j+=i) prime[j]=0;
        }
    for (int i=2;i<=N;i++)
        if (prime[i]) nt.push_back(i);
}
int get(int u)
{
    if (r[u]==u) return u;
    else return r[u]=get(r[u]);
}
void Union(int u,int v)
{
    u=get(u);
    v=get(v);
    r[v]=u;
}
void process(int a,int b,int p)
{
    int res=0;
    for (int i=a;i<=b;i++) d[i]=0;
    for (int i=a;i<=b;i++) r[i]=i;
    for (int x : nt)
        if (x>=p)
    {
        int f_val=-1;
        for (int i=a;i<=b;i++) 
            if (i%x==0) 
            {
                f_val=i;
                break;
            }
        if (f_val!=-1)
        {
            for (int i=a;i<=b;i++)
                if (i%x==0 && i!=f_val) Union(f_val,i);
        }
    }
    for (int i=a;i<=b;i++)
    {
        int x=get(i);
        if (!d[x])
        {
            res++;
            d[x]=1;
        }
    }
    cout<<"Case #"<<stt<<": "<<res<<endl;
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
        stt++;
        int a,b,p;
        cin>>a>>b>>p;    
        process(a,b,p);	
    }
}

