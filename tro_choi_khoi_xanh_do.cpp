#include <iostream>
using namespace std;
int n,m;
pair<int,int> res1,res2;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    int a[m+n+1];
    // xanh 1 m
    // do 0 n
    // Ti chon khoi xanh truoc
    int tmp1=n,tmp2=m,ti=0,teo=0;
    a[1]=1;
    tmp2--;
    for (int i=2;i<=n+m;i++)
    {
        // luot chon cua teo
        if (i%2==0)
        {
            if (a[i-1] && tmp1) 
            {
                a[i]=0;
                tmp1--;
                teo++;
            }  
            else 
            if (!a[i-1] && tmp2)
            {
                a[i]=1;
                tmp2--;
                teo++;
            }
            else 
            {
                a[i]=a[i-1];
                if (a[i]) tmp2--;
                else tmp1--;
                ti++;
            }
        }
        else //luot chon cua ti
        {
            if (a[i-1] && tmp2)
            {
                a[i]=1;
                tmp2--;
                ti++;
            }
            else 
            if (!a[i-1] && tmp1)
            {
                a[i]=0;
                tmp1--;
                ti++;
            }
            else
            {
                a[i]=1-a[i-1];
                if (a[i]) tmp2--;
                else tmp1--;
                teo++;
            }
        }
    }
    res1.first=ti; res1.second=teo;
    ti=teo=0; 
    tmp1=n; tmp2=m;
    // Ti chon do truoc
    a[1]=0;
    tmp1--;
    for (int i=2;i<=n+m;i++)
    {
        // luot chon cua teo
        if (i%2==0)
        {
            if (a[i-1] && tmp1) 
            {
                a[i]=0;
                tmp1--;
                teo++;
            }  
            else 
            if (!a[i-1] && tmp2)
            {
                a[i]=1;
                tmp2--;
                teo++;
            }
            else 
            {
                a[i]=a[i-1];
                if (a[i]) tmp2--;
                else tmp1--;
                ti++;
            }
        }
        else //luot chon cua ti
        {
            if (a[i-1] && tmp2)
            {
                a[i]=1;
                tmp2--;
                ti++;
            }
            else 
            if (!a[i-1] && tmp1)
            {
                a[i]=0;
                tmp1--;
                ti++;
            }
            else
            {
                a[i]=1-a[i-1];
                if (a[i]) tmp2--;
                else tmp1--;
                teo++;
            }
        }
    }
    res2.first=ti; res2.second=teo;
    if (res1.first>res2.first) 
    {
        cout<<res1.first<<" "<<res1.second;
    }
    else cout<<res2.first<<" "<<res2.second;
}

