#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define bit(i,n) ((n>>i)&1)
#define set_on(i,n) ((n) | (1<<i))
#define set_off(i,n) ((n) & ~(1<<i)) 
#define pii pair<int,int>
const int max_char=20;
#define maxn 
string s;
bool have[max_char];
int dp[1<<max_char];
// dp[mask] là độ dài lớn nhất của chuỗi con khác biệt 
// liên tiếp có MỘT SỐ ký tự trong mask được bật
void process()
{
    for (int i=0;i<s.length();i++)
    {
        memset(have,false,sizeof(have));
        int mask=0;
        for (int j=i;j<s.length();j++)
        {
            if (!have[s[j]-'a'])
                have[s[j]-'a']=true;
            else
                break;
            mask=set_on(s[j]-'a',mask);
            dp[mask]=__builtin_popcount(mask);
            // dp[mask]=số bit 1 vì lúc này mask thỏa mãn trong đoạn i-j chỉ gồm các ký tự khác nhau
        }
    }
    for (int mask=0;mask<(1<<max_char);mask++)
    {
        for (int j=0;j<max_char;j++)
            if (bit(j,mask))
                dp[mask]=max(dp[mask],dp[set_off(j,mask)]);
    }
    int answer=0;
    for (int mask=0;mask<(1<<max_char);mask++)
        if (dp[mask] == __builtin_popcount(mask))
        {
            // kiểm tra mask có gồm toàn các ký tự riêng biệt hay không
            // tránh việc mask giao với reverse_mask
            int reverse_mask=((1<<max_char)-1) ^ mask;
            // reverse_mask là mask đảo của mask với độ dài 20
            answer=max(answer,dp[mask]+dp[reverse_mask]);
        }
    cout<<answer;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    process();
}
