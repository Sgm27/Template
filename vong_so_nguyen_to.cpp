#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1025;
int prime[1050],n,cnt=0,x[25];
bool d[1025];
long ketQua[10] = {0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144};
vector<int> nt;
vector<vector<int>> res;
void input()
{
    memset(d,true,sizeof(d));
    cin>>n;
}
void sang()
{
    for (int i=1;i<=N;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i=2;i<=sqrt(N);i++)
        if (prime[i])
            for (int j=i*i;j<=N;j+=i) prime[j]=0;
    for (int i=1;i<=N;i++) 
        if (prime[i]) nt.push_back(i);
}
void in()
{
    cnt++;
    if (cnt<=10000) 
    {
        for (int i=1;i<=2*n;i++) cout<<x[i]<<" ";
        cout<<endl;
    }
}
void Try(int i)
{
    if (cnt>=10000) return;
    for (int k : nt)
        if (k-x[i-1]>0 && k-x[i-1]<=2*n && d[k-x[i-1]])
    {
        d[k-x[i-1]]=false;
        x[i]=k-x[i-1];
        if (i==2*n)
        {
            if (prime[x[2*n]+1]) in();
        }
        else Try(i+1);
        d[k-x[i-1]]=true;
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    sang();
    input();
    d[1]=false;
    x[1]=1;
    cout<<ketQua[n]<<endl;
    Try(2);
}

