#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll x[15],d[15],total_sum=0,sub_sum,a[15],sum[10],res=0,cnt[10];
void xuly()
{
    for (int i=1;i<=6;i++) 
        if (sum[i]!=sub_sum) return;
    res++;
}
void Try(int i)
{
    for (int j=1;j<=12;j++)
        for (int k=1;k<=6;k++)
            if (d[j]<2 && sum[k]+a[j]<=sub_sum && cnt[k]<4) 
            {
                sum[k]+=a[j];
                cnt[k]++;
                d[j]++;
                if (i==24) 
                    xuly();
                else Try(i+1);
                sum[k]-=a[j];
                d[j]--;
                cnt[k]--;
            } 
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (1)
    {
        for (int i=1;i<=6;i++) 
		{
			sum[i]=0;
			cnt[i]=0;
		}
        int check=0;
        for (int i=1;i<=12;i++) 
        {
            cin>>a[i];
            total_sum+=a[i];
            if (a[i]) check=1;
        }
        if (!check) return 0;
        total_sum*=2;
        if (total_sum%6) 
        {
            cout<<0<<endl;
            continue;
        }
        else sub_sum=total_sum/6;
        Try(1);
    }
}

