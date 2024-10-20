#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cp(int k)
{
	int tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
int solve(int n)
{
	int cnt=0;
	for (int i=1;i<=sqrt(n);i++)
		if (n%i==0)
		{
			if (i%2==0) cnt++;
			if ((n/i) %2==0) cnt++;
		}
	if (cp(n) && (int)(sqrt(n))%2==0) cnt--;
	return cnt;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
}
