#include <stdio.h>
#include <string.h>
int stack[100002];//input-수열 저장 stack-스택
char move[200003]={'\0',};//+-저장용 
int main ()
{
	int n,num=0,top=-1,i,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		if(m>num)//입력값이 stack에 넣을 값보다 작을 경우,
			while(m>num){
				stack[++top]=++num;//stack에 넣어주며 넣을값 키우기
				move[strlen(move)]='+';	
			}
		else//만일 같거나 더 클경우
			if(stack[top]>m){//더 클 경우, 수열을 만들수 없다 판단, 출력 불가.
				printf("NO");
				return 0;
			}
        stack[top--];//pop
		move[strlen(move)]='-';
	}
	for(i=0;i<strlen(move); i++)
		printf("%c\n",move[i]);
	return 0;
}