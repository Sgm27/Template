/*
    đếm số lượng palindrome trong xâu S
    gọi calc_le là tại d[i] là số lượng palindrome nhận i làm tâm và có độ dài lẻ
    gọi calc_chan là tại d[i] là số lượng palindrome nhận i làm tâm và có độ dài chẵn
    chỉ xét độ dài >1
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
string s;
int n,ans=0;
void calc_le()
{
    int d[maxn]={};
    int l=0,r=-1;
    for (int i=0;i<n;i++)
    {
        int k=0;
        if (i<=r) k=min(r-i,d[r-i+l]);
        while (i+k+1<n && i-k-1>=0 && s[i+k+1]==s[i-k-1]) k++;
        d[i]=k;
        if (i+k>r) l=i-k, r=i+k;
    }
    for (int i=0;i<n;i++) cout<<d[i]<<" "; cout<<"\n";
    for (int i=0;i<n;i++) ans+=d[i];
}
void calc_chan()
{
    int d[maxn]={};
    int l=0,r=-1;
    for (int i=0;i<n;i++)
    {
        int k=0;
        if (i<=r) k=min(r-i+1,d[r-i+l+1]);
        while (i+k+1<n && i-k-1>=0 && s[i+k]==s[i-k-1]) k++;
        d[i]=k;
        if (i+k-1>r) l=i-k, r=i+k-1;
    }
    for (int i=0;i<n;i++) cout<<d[i]<<" "; cout<<"\n";
    for (int i=0;i<n;i++) ans+=d[i];
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    n=s.length(); 
    calc_le();
    calc_chan();
    cout<<ans+n;
}

