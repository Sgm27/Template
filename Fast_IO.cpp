#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define X first
#define Y second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
int n;
struct data
{
    int x,y,pos;
} A[105];

inline int Read_int(){
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    int res = ch - '0';
    for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()){
        res = res * 10 + ch - '0';
    }
    return res;
}
#define pc(x) putchar(x);
inline void Write_int (ll n)
{
    ll N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;}
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

void Input(){
    n = Read_int();
    FOR(i, 1, n){
        A[i].x = Read_int();
        A[i].y = Read_int();
        A[i].pos = i;
    }
}
inline void Solve()
{
    FOR(i,1,n) Write_int(A[i].x), putchar('\n');
}
int main(){
    freopen("thu.inp","r",stdin);
    Input();
    Solve();
}
