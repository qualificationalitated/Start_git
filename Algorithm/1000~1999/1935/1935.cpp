#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,alpha[26]={0,},top=0;
	double stack[27]={0,};
	char input[102];
	scanf("%d",&n);
	scanf("%s",input);
	for(int i=0;i<n;i++)	scanf("%d",&alpha[i]);
	for(int i=0;i<strlen(input);i++){
		switch (input[i])
		{
		case '+':
			stack[top-1] = stack[top-1] + stack[top];
			top--;
			break;
		case '-':
			stack[top-1] = stack[top-1] - stack[top];
			top--;
			break;
		case '*':
			stack[top-1] = stack[top-1] * stack[top];
			top--;
			break;
		case '/':
			stack[top-1] = stack[top-1] / stack[top];
			top--;
			break;
		
		default:
			stack[++top]=alpha[input[i]-'A'];
			break;
		}	
	}
	printf("%.2f",stack[1]);
	return 0;
}