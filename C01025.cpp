#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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
	int xa,xb,xc,xd,ya,yb,yc,yd;
	scanf("%d %d %d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
	int xmax=max(xa,max(xb,max(xc,xd)));
	int ymax=max(ya,max(yb,max(yc,yd)));
	int xmin=min(xa,min(xb,min(xc,xd)));
	int ymin=min(ya,min(yb,min(yc,yd)));
	int tmp=max(ymax-ymin,xmax-xmin);
	printf("%d",tmp*tmp);
}

