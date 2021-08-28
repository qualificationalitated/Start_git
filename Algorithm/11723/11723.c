#include<stdio.h>
int num[21]={0,};
int main()
{
	int m,n,i;
	char command[8];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",command);
		if(command[1]=='l')
			for(i=0;i<=20;i++)//all
				num[i]=1;
		else if(command[0]=='e')//empty
			for(i=0;i<=20;i++)
				num[i]=0;
		else
		{
			scanf("%d",&n);
			if(command[1]=='d')//add
				num[n]=1;
			else if(command[0]=='r')//remove
				num[n]=0;
			else if(command[0]=='c')//check
				printf("%d\n",num[n]);
			else if(command[0]=='t')//toggle
				if(num[n]) num[n]=0;
				else num[n]=1;
		}
	}
	return 0;
}