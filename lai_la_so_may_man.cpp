#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
void process()
{
    int tmp=n/7,check=0;
    pair<int,int> sum1,sum2;
    while (tmp)
    {
        if ((n-tmp*7)%4==0) 
        {
            sum1.first=tmp+(n-tmp*7)/4;
            check=1;
            break;
        }
        tmp--;
    }
    sum1.second=tmp;
    tmp=n/4;
    while (tmp)
    {
        if ((n-tmp*4)%7==0)
        {
            sum2.first=tmp+(n-tmp*4)/7;
            check=1;
            break;
        }
        tmp--;
    }
    sum2.second=tmp;
    if (!check)
    {
        cout<<"-1";
        return;
    }
    if (sum2.first==sum1.first) 
    { 
        for (int i=1;i<=sum2.first-sum2.second;i++) cout<<"4";
        for (int i=1;i<=sum2.second;i++) cout<<"7";
        return;
    }
    if (sum1.first)
    {
        for (int i=1;i<=sum1.first-sum1.second;i++) cout<<"4";
        for (int i=1;i<=sum1.second;i++) cout<<"7";
    }
    else 
    {
        for (int i=1;i<=sum2.second;i++)  cout<<"4";
        for (int i=1;i<=sum2.first-sum2.second;i++) cout<<"7";
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    process();
}

