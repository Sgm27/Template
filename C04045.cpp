#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cnt_chan,cnt_le,cnt;

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
	int tc;
	scanf("%d",&tc);
	getchar();
	while (tc--)
	{
		cnt_le=0; cnt_chan=0; cnt=0;
		char tmp[100005];
		gets(tmp);
		char *token=strtok(tmp," ");
		while (token != NULL)
		{
			cnt++;
			int t=atoi(token);
			if (t%2) cnt_le++;
			else cnt_chan++;
			token=strtok(NULL," ");
		}
		if ((cnt%2==0 && cnt_chan>cnt_le) || (cnt%2!=0 && cnt_chan<cnt_le)) printf("YES\n");
		else printf("NO\n");
	}
}

