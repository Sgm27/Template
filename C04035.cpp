#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const int Max=1e7;
int n,time_up=0,time_down=0,min_up=Max,min_down=Max;

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
	scanf("%d",&n);
	while (n--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		time_up+=x;
		time_down+=y;
		min_up=min(min_up,x);
		min_down=min(min_down,y);
	}
	if (time_up>time_down)
		printf("%d",time_up+min_down);
	else
		printf("%d",time_down+min_up);
}

