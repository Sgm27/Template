#include<bits/stdc++.h>
#include "debug.h"

#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define vi vector<int>
#define TASK "check"

long long GetRandom(long long Min, long long Max)
{
    return Min + (long long)(rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX));
}

void MakeTest()
{
    ofstream cout("thu.inp");
    int tc = GetRandom(1,10);
    cout<<tc<<"\n";
    while (tc--)
    {
        int n = GetRandom(1,5);
        int m = GetRandom(5,5);
        cout<<n<<" "<<m<<"\n";
        FOR(i,1,m)
        {
            int u = GetRandom(1,n);
            int v = GetRandom(1,n);
            cout<<u<<" "<<v<<" ";
        }
        cout<<"\n";
    }
} 
signed main()
{
    srand(time(NULL));
    int NTEST = 10;
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        MakeTest();
        system(TASK "_trau.exe");
        system(TASK ".exe");
        if (system("fc " TASK ".out " TASK ".ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
