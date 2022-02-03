#include<stdio.h>
#include<string.h>
typedef struct poke{//포켓몬 구조체
	char name[23];
	int number;
}pMon;
pMon list[100003];//입력
char copy[100003][23];
int cmp(const void *a,const void *b)//포켓몬 이름별로 정렬
{
	pMon *p1=(pMon*)a;
	pMon *p2=(pMon*)b;
	return strcmp(p1->name,p2->name);
}
int main()
{
	int n,m;
	char s[23];
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++){//입력, 입력하면서 순서 저장
		scanf("%s",list[i].name);
		strcpy(copy[i],list[i].name);
		list[i].number=i;
	}
	qsort(list,n,sizeof(pMon),cmp);
	while(m--)
	{
		scanf("%s",s);
		if(47<s[0]&&s[0]<58){//숫자라면
			int ten=1,num=0;
			for (int i=strlen(s)-1;i>=0;i--){
				num+=(s[i]-'0')*ten;
				ten*=10;
			}
			printf("%s\n",copy[num-1]);//복사된 배열에서 숫자에 맞는 항목 출력.
		}
		else{//문자면
            int head=0,tail=n,mid,check;
            while(head<=tail){
                mid=(head+tail)/2;
                check=strcmp(list[mid].name,s);
                if(check==0){
                    printf("%d\n",list[mid].number+1);
                    break;
                }
                else if(check<0)//앞글자가 더 작아요
                    head=mid+1;
                else
                    tail=mid-1;
            }
		}
	}
	return 0;
}