#include<stdio.h>
#include<string.h>
int main()
{
	char s[100003];
	int devided=0,pipe=0;
	scanf("%s",s);
	for (int i = 0; i < strlen(s); i++)
	{
		if(s[i]=='(')
			pipe++;
		else{
			pipe--;
			if (s[i-1]=='(')
				devided+=pipe;
			else
				devided+=1;	
		}
	}
	printf("%d",devided);
	return 0;
}