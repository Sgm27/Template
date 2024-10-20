#include<bits/stdc++.h>
 
#define lmao cout<<"\nLick My Ass onii-chann ~";
#define alphaa "abcdefghijklmnopqrstuvwxyz"
#define ALPHAA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define mp make_pair
#define fi first
#define se second
#define pb push_back
 
/******************************************************************************
 *                                                                            *
 *                            Lick My Ass Onii~chan                           *
 *                                                                            *
 *                                                                            *
 *****************************************************************************/
 
using namespace std;
 
typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
 
const ld pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;
const int oo = INT_MAX;
const int noo = INT_MIN;
 
int n;
int x,y;
int a[9][9] = {0};
 
void init(){
	cin>>n>>x>>y;
}
 
int xqX[] = {2,2,1,1,-1,-1,-2,-2};
int xqY[] = {1,-1,2,-2,2,-2,1,-1};
 
void xuat(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
 
void Try(int index,int r,int c){
	for(int i=0;i<8;i++){
		int X=r + xqX[i]; 
		int Y=c + xqY[i];
		if( X > 0 && X<=n && Y > 0 && Y<=n && a[X][Y]==0){
			a[X][Y]=index;
			if(index<n*n) {
				Try(index+1,X,Y);
				a[X][Y]=0;
			}
			else xuat();
 		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	init();
	a[x][y]=1;
	Try(2,x,y);
return 0;
}
