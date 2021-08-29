#include<stdio.h>
int main()
{
	int n,m=0;
	scanf("%d",&n);
	while(n){
		m+=n%2;
		n/=2;
	}
	printf("%d",m);
	return 0;
}

/*
1. 지민이가 가지고 있는 막대의 길이를 모두 더한다. 처음에는 64cm 막대 하나만 가지고 있다. 이때, 합이 X보다 크다면, 아래와 같은 과정을 반복한다.
2. 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
3. 만약, 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같다면, 위에서 자른 막대의 절반 중 하나를 버린다.
4. 이제, 남아있는 모든 막대를 풀로 붙여서 Xcm를 만든다.
위 1,2,3,4의 동작을 수행한다고 했을때, 입력받은 64보다 작거나 같은 길이는 총 몇개의 막대로 만들수 있는가.

막대의 갯수가 2진수로 바뀌었을때의 1의 갯수와 같다는것을 발견
2진수로 바꿔가며 나머지만을 더하였다.
*/
