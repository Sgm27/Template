#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char s[100005];

int max(int a,int b)
{
	if (a>b) return a;
	return b;
}
int min(int a,int b)
{
	if (a>b) return b;
	return a;
}


int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%s",s);
	int ngoac_don=0,ngoac_kep=0,ngoac_vuong=0,nhay_don=0,nhay_kep=0;
	for (int i=0;i<strlen(s);i++) 
	{
		if (s[i]=='(') ngoac_don++;
		if (s[i]==')') ngoac_don--;
		if (s[i]=='[') ngoac_vuong++;
		if (s[i]==']') ngoac_vuong--;
		if (s[i]=='{') ngoac_kep++;
		if (s[i]=='}') ngoac_kep--;
		if (s[i]==(char)(39)) nhay_don++;
		if (s[i]=='"') nhay_kep++;
		if (ngoac_don<0 || ngoac_kep<0 || ngoac_vuong<0) 
		{
			printf("0");
			return 0;
		}
	}
	if (nhay_don%2 || nhay_kep%2) 
	{
		printf("0");
		return 0;
	}
	if (!ngoac_don && !ngoac_kep && !ngoac_vuong)
	{
		printf("1");
		return 0;
	}
	printf("0");
}

