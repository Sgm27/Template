#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll d,max_bike,time_bike,time_walk,time_fix;
void input()
{
    cin>>d>>max_bike>>time_bike>>time_walk>>time_fix;
}
void process()
{
    ll time=0;
    if (max_bike>=d)
    {
        cout<<d*time_bike;
        return;
    }
    d-=max_bike;
    time=max_bike*time_bike;
    if (d<=max_bike)
    {
        cout<<time+min(time_fix+d*time_bike,d*time_walk);
        return;
    }
    ll time_for_bike=time_fix+max_bike*time_bike;
    ll time_for_walk=time_walk*max_bike;
    if (time_for_walk<=time_for_bike) 
    {
        cout<<time+time_walk*d;
        return;
    }
    time=time+d/max_bike * time_for_bike;
    d%=max_bike;
    cout<<time+min(d*time_walk,time_fix+d*time_bike);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

