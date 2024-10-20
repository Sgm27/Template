/*
    cho tập S rỗng 
        1 x : thêm x vào tập S
        2 k : in ra phần tử bé thứ k
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
#define maxbit 29
struct node{
    int exist=0,count=0;
    int child[2];
    ll val;
};
node t[maxn];
int cnt=0;
void add(ll n)
{
    int x=0;
    for (int i=maxbit;i>=0;i--)
    {
        int id=(n>>i)&1;
        if (t[x].child[id]==0) t[x].child[id]=++cnt;
        x=t[x].child[id];
        t[x].count++;
    }
    t[x].exist++;
    t[x].val=n;
}
ll find(int k)
{
    int x=0;
    for (int i=maxbit;i>=0;i--)
    {
        int left=t[x].child[0];
        if (left && t[left].count>=k)
            x=left;
        else
        {
            x=t[x].child[1]; 
            if (left) k-=t[left].count;
        }
    }
    return t[x].val;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    while (n--)
    {
        int type; ll x;
        cin>>type>>x;
        if (type==1) add(x);
        else cout<<find(x)<<"\n";
    } 
}

