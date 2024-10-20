#include<iostream>
#include<math.h>
using namespace std;
using ll = long long;
int n,m;
int prime[10000007];
void input()
{
    cin>>n>>m;
}
void sang(int l,int r)
{
	for (int i=0;i<=r-l+1;i++) prime[i]=1;
	for (int i=2;i<=sqrt(r);i++)
		for (int j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
			prime[j-l]=0;
    int it=max(m,2);
	while (n)
    {
        if (prime[it-l]) 
        {
            cout<<it<<" ";
            n--;
        }
        it++;
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    sang(m,(int)(m+7*1e5));
}

