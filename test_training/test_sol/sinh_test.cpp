#include <bits/stdc++.h>
using namespace std;
#define cout inp
#define int long long
const int ttest = 60;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) %
                   (h - l + 1);
}
#define maxn 2003
// #define A 1000000000
#define A 1000000000000000000
#define H 100000
#define M 100000
#define N 1000000
#define Q 100000
#define X 2000000000
#define K 1000000000
#define W 100000
#define T 10
void sinh1(int x)
{
    int limitN = 1e2, limitQ = 100, LimitVal = 1e6;
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    long long a, c, h, k, n, m, q, t, w;
    n = Rand(1, limitN);
    q = Rand(1, limitQ);
    inp << n << " " << q << "\n";
    for (int i = 1; i <= n; i++)
        inp << Rand(1, LimitVal) << " ";
    while (q--)
    {
        int l = Rand(1, n);
        int r = Rand(l, n);
        inp << l << " " << r << "\n";
    }
}
void sinh2(int x)
{
    int limitN = 1e3, limitQ = 1000, LimitVal = 1e6;
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    long long a, c, h, k, n, m, q, t, w;
    n = Rand(1, limitN);
    q = Rand(1, limitQ);
    inp << n << " " << q << "\n";
    for (int i = 1; i <= n; i++)
        inp << Rand(1, LimitVal) << " ";
    while (q--)
    {
        int l = Rand(1, n);
        int r = Rand(l, n);
        inp << l << " " << r << "\n";
    }
}
void sinh3(int x)
{
    int limitN = 1e5, limitQ = 1e5, LimitVal = 1e6;
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    long long a, c, h, k, n, m, q, t, w;
    n = Rand(1, limitN);
    q = Rand(1, limitQ);
    inp << n << " " << q << "\n";
    for (int i = 1; i <= n; i++)
        inp << Rand(1, LimitVal) << " ";
    while (q--)
    {
        int l = Rand(1, n);
        int r = Rand(l, n);
        inp << l << " " << r << "\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    for (int i = 1; i <= ttest; i++)
    {
        if (i <= ttest / 3)
            sinh1(i);
        else if (i <= 2 * ttest / 3)
            sinh2(i);
        else
            sinh3(i);
    }
    return 0;
}