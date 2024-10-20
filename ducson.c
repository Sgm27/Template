#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h> 
#include<ctype.h> 
#define ll long long
char a[1005][1005];
int b[100005];
char s[100005];
char to_lower(char c)
{
	if(c >= 'A' && c <= 'Z')
	{
		c+=32;
	}
	return c;
}
int main()
{
	gets(s);
	int n = 0;
	char *p = strtok(s," ");
	while(p!= NULL)
	{
		strcpy(a[n],p);
		n++;
		p = strtok(NULL," ");
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<strlen(a[i]);j++)
		{
			a[i][j] = to_lower(a[i][j]);
		}
	}
	for(int i = 0;i<n;i++)
	{
		if(b[i] == 0)
		{
			int cnt =  1;
			for(int j = i+1;j<n;j++)
			{
				if(strcmp(a[i],a[j]) == 0)
				{
					cnt++;
					b[j] = 1;
				}
			}
			printf("%s %d\n",a[i],cnt);
		}
	}
}