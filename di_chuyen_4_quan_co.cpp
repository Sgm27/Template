#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int int_fast16_t
#define vi vector<int>
#define pii pair<int,int>
#define maxn 
int dp[8][8][8][8][8][8][8][8];
bool ans;
struct save{
    int xx1,yy1,xx2,yy2,xx3,yy3,xx4,yy4;
    friend bool operator==(const save &a, const save &b)
    {
        return (a.xx1 == b.xx1 && a.xx2 == b.xx2 && a.xx3 == b.xx3 && a.xx4 == b.xx4
        && a.yy1 == b.yy1 && a.yy2 == b.yy2 && a.yy3 == b.yy3 && a.yy4 == b.yy4);
    }
};
save S,T;
int mark[8][8];
void bfs_forward()
{
    queue<save> q;
    dp[S.xx1][S.yy1][S.xx2][S.yy2][S.xx3][S.yy3][S.xx4][S.yy4] = 0;
    if (dp[T.xx1][T.yy1][T.xx2][T.yy2][T.xx3][T.yy3][T.xx4][T.yy4] != -1)
    {
        ans = true;
        cout<<"YES\n";
        return;
    }
    q.push(S);
    while (!q.empty())
    {
        save cur = q.front();
        q.pop();
        if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] == 4) continue;
        int cur_step = dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4];
        mark[cur.xx1][cur.yy1] = 1;
        mark[cur.xx2][cur.yy2] = 1;
        mark[cur.xx3][cur.yy3] = 1;
        mark[cur.xx4][cur.yy4] = 1;

        int nx = cur.xx1;
        while (nx >= 0 && mark[nx][cur.yy1]) nx--;
        if (nx != -1)
        {
            dp[nx][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.xx1;
            cur.xx1 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx1 = tmp;
        } 
        nx = cur.xx1;
        while (nx <= 7 && mark[nx][cur.yy1]) nx++;
        if (nx != 8)
        {
            dp[nx][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.xx1;
            cur.xx1 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx1 = tmp;
        }  

        nx = cur.xx2;
        while (nx >= 0 && mark[nx][cur.yy2]) nx--;
        if (nx != -1)
        {
            dp[cur.xx1][cur.yy1][nx][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.xx2;
            cur.xx2 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx2 = tmp;
        } 
        nx = cur.xx2;
        while (nx <= 7 && mark[nx][cur.yy2]) nx++;
        if (nx != 8)
        {
            dp[cur.xx1][cur.yy1][nx][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.xx2;
            cur.xx2 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx2 = tmp;
        }

        nx = cur.xx3;
        while (nx >= 0 && mark[nx][cur.yy3]) nx--;
        if (nx != -1)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][nx][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.xx3;
            cur.xx3 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx3 = tmp;
        } 
        nx = cur.xx3;
        while (nx <= 7 && mark[nx][cur.yy3]) nx++;
        if (nx != 8)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][nx][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.xx3;
            cur.xx3 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx3 = tmp;
        }  

        nx = cur.xx4;
        while (nx >= 0 && mark[nx][cur.yy4]) nx--;
        if (nx != -1)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][nx][cur.yy4] = cur_step + 1;
            int tmp = cur.xx4;
            cur.xx4 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx4 = tmp;
        } 
        nx = cur.xx4;
        while (nx <= 7 && mark[nx][cur.yy4]) nx++;
        if (nx != 8)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][nx][cur.yy4] = cur_step + 1;
            int tmp = cur.xx4;
            cur.xx4 = nx;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.xx4 = tmp;
        }

        int ny = cur.yy1;
        while (ny >= 0 && mark[cur.xx1][ny]) ny--;
        if (ny != -1)
        {
            dp[cur.xx1][ny][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.yy1;
            cur.yy1 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy1 = tmp;
        } 
        ny = cur.yy1;
        while (ny <= 7 && mark[cur.xx1][ny]) ny++;
        if (ny != 8)
        {
            dp[cur.xx1][ny][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.yy1;
            cur.yy1 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy1 = tmp;
        }  

        ny = cur.yy2;
        while (ny >= 0 && mark[cur.xx2][ny]) ny--;
        if (ny != -1)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][ny][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.yy2;
            cur.yy2 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy2 = tmp;
        } 
        ny = cur.yy2;
        while (ny <= 7 && mark[cur.xx2][ny]) ny++;
        if (ny != 8)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][ny][cur.xx3][cur.yy3][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.yy2;
            cur.yy2 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy2 = tmp;
        }

        ny = cur.yy3;
        while (ny >= 0 && mark[cur.xx3][ny]) ny--;
        if (ny != -1)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][ny][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.yy3;
            cur.yy3 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy3 = tmp;
        } 
        ny = cur.yy3;
        while (ny <= 7 && mark[cur.xx3][ny]) ny++;
        if (ny != 8)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][ny][cur.xx4][cur.yy4] = cur_step + 1;
            int tmp = cur.yy3;
            cur.yy3 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy3 = tmp;
        }  

        ny = cur.yy4;
        while (ny >= 0 && mark[cur.xx4][ny]) ny--;
        if (ny != -1)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][ny] = cur_step + 1;
            int tmp = cur.yy4;
            cur.yy4 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy4 = tmp;
        } 
        ny = cur.yy4;
        while (ny <= 7 && mark[cur.xx4][ny]) ny++;
        if (ny != 8)
        {
            dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][ny] = cur_step + 1;
            int tmp = cur.yy4;
            cur.yy4 = ny;
            if (cur == T)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            q.push(cur);
            cur.yy4 = tmp;
        }

        mark[cur.xx1][cur.yy1] = 0;
        mark[cur.xx2][cur.yy2] = 0;
        mark[cur.xx3][cur.yy3] = 0;
        mark[cur.xx4][cur.yy4] = 0;

    }
}

void bfs_back()
{
    queue<pair<save, int>> q;
    q.push({T, 0});
    while (!q.empty())
    {
        save cur = q.front().first;
        int cur_step = q.front().second;
        q.pop();
        if (cur_step == 4) continue;
        mark[cur.xx1][cur.yy1] = 1;
        mark[cur.xx2][cur.yy2] = 1;
        mark[cur.xx3][cur.yy3] = 1;
        mark[cur.xx4][cur.yy4] = 1;

        int nx = cur.xx1;
        while (nx >= 0 && mark[nx][cur.yy1]) nx--;
        if (nx != -1)
        {
            if (dp[nx][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1) 
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx1;
            cur.xx1 = nx;
            q.push({cur, cur_step + 1});
            cur.xx1 = tmp;
        } 
        nx = cur.xx1;
        while (nx <= 7 && mark[nx][cur.yy1]) nx++;
        if (nx != 8)
        {
            if (dp[nx][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1) 
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx1;
            cur.xx1 = nx;
            q.push({cur, cur_step + 1});
            cur.xx1 = tmp;
        }  

        nx = cur.xx2;
        while (nx >= 0 && mark[nx][cur.yy2]) nx--;
        if (nx != -1)
        {
            if (dp[cur.xx1][cur.yy1][nx][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx2;
            cur.xx2 = nx;
            q.push({cur, cur_step + 1});
            cur.xx2 = tmp;
        } 
        nx = cur.xx2;
        while (nx <= 7 && mark[nx][cur.yy2]) nx++;
        if (nx != 8)
        {
            if (dp[cur.xx1][cur.yy1][nx][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx2;
            cur.xx2 = nx;
            q.push({cur, cur_step + 1});
            cur.xx2 = tmp;
        }

        nx = cur.xx3;
        while (nx >= 0 && mark[nx][cur.yy3]) nx--;
        if (nx != -1)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][nx][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx3;
            cur.xx3 = nx;
            q.push({cur, cur_step + 1});
            cur.xx3 = tmp;
        } 
        nx = cur.xx3;
        while (nx <= 7 && mark[nx][cur.yy3]) nx++;
        if (nx != 8)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][nx][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx3;
            cur.xx3 = nx;
            q.push({cur, cur_step + 1});
            cur.xx3 = tmp;
        }  

        nx = cur.xx4;
        while (nx >= 0 && mark[nx][cur.yy4]) nx--;
        if (nx != -1)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][nx][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx4;
            cur.xx4 = nx;
            q.push({cur, cur_step + 1});
            cur.xx4 = tmp;
        } 
        nx = cur.xx4;
        while (nx <= 7 && mark[nx][cur.yy3]) nx++;
        if (nx != 8)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][nx][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.xx4;
            cur.xx4 = nx;
            q.push({cur, cur_step + 1});
            cur.xx4 = tmp;
        }  

        int ny = cur.yy1;
        while (ny >= 0 && mark[cur.xx1][ny]) ny--;
        if (ny != -1)
        {
            if (dp[cur.xx1][ny][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy1;
            cur.yy1 = ny;
            q.push({cur, cur_step + 1});
            cur.yy1 = tmp;
        } 
        ny = cur.yy1;
        while (ny <= 7 && mark[cur.xx1][ny]) ny++;
        if (ny != 8)
        {
            if (dp[cur.xx1][ny][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy1;
            cur.yy1 = ny;
            q.push({cur, cur_step + 1});
            cur.yy1 = tmp;
        }  

        ny = cur.yy2;
        while (ny >= 0 && mark[cur.xx2][ny]) ny--;
        if (ny != -1)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][ny][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy2;
            cur.yy2 = ny;
            q.push({cur, cur_step + 1});
            cur.yy2 = tmp;
        } 
        ny = cur.yy2;
        while (ny <= 7 && mark[cur.xx2][ny]) ny++;
        if (ny != 8)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][ny][cur.xx3][cur.yy3][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy2;
            cur.yy2 = ny;
            q.push({cur, cur_step + 1});
            cur.yy2 = tmp;
        }

        ny = cur.yy3;
        while (ny >= 0 && mark[cur.xx3][ny]) ny--;
        if (ny != -1)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][ny][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy3;
            cur.yy3 = ny;
            q.push({cur, cur_step + 1});
            cur.yy3 = tmp;
        } 
        ny = cur.yy3;
        while (ny <= 7 && mark[cur.xx3][ny]) ny++;
        if (ny != 8)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][ny][cur.xx4][cur.yy4] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy3;
            cur.yy3 = ny;
            q.push({cur, cur_step + 1});
            cur.yy3 = tmp;
        }  

        ny = cur.yy4;
        while (ny >= 0 && mark[cur.xx4][ny]) ny--;
        if (ny != -1)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][ny] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy4;
            cur.yy4 = ny;
            q.push({cur, cur_step+1});
            cur.yy4 = tmp;
        } 
        ny = cur.yy4;
        while (ny <= 7 && mark[cur.xx4][ny]) ny++;
        if (ny != 8)
        {
            if (dp[cur.xx1][cur.yy1][cur.xx2][cur.yy2][cur.xx3][cur.yy3][cur.xx4][ny] != -1)
            {
                ans = true;
                cout<<"YES\n";
                return;
            }
            int tmp = cur.yy4;
            cur.yy4 = ny;
            q.push({cur, cur_step+1});
            cur.yy4 = tmp;
        }

        mark[cur.xx1][cur.yy1] = 0;
        mark[cur.xx2][cur.yy2] = 0;
        mark[cur.xx3][cur.yy3] = 0;
        mark[cur.xx4][cur.yy4] = 0;

    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        memset(dp, -1, sizeof dp);
        ans = false;
        cin>>S.xx1>>S.yy1>>S.xx2>>S.yy2>>S.xx3>>S.yy3>>S.xx4>>S.yy4;
        S.xx1--, S.xx2--, S.xx3--, S.xx4--;
        S.yy1--, S.yy2--, S.yy3--, S.yy4--;
        cin>>T.xx1>>T.yy1>>T.xx2>>T.yy2>>T.xx3>>T.yy3>>T.xx4>>T.yy4;
        T.xx1--, T.xx2--, T.xx3--, T.xx4--;
        T.yy1--, T.yy2--, T.yy3--, T.yy4--;
        bfs_forward();
        if (ans) continue;
        bfs_back();
        if (ans == false) cout<<"NO\n";
    }
}
