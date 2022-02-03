// 주의! 본 코드는 시간초과 코드입니다.
// 죽어도 C 이진으로 안풀려서 그냥...그냥 올려봅니다.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct sitepw{
    char add[22],pw[22];
}sp;
sp list[100002];
int cmp(const void *a, const void *b){
    sp *A=(sp*)a,*B=(sp*)b;
    return strcmp(A->add,B->add);
}
int find(int head,int tail,char *s)
{
    int mid=(head+tail)/2,r;
    r=strcmp(list[mid].add,s);
    if(!r)
        return mid;
    else if(r==1)
        return find(head,mid-1,s);
    else
        return find(mid+1,tail,s);
}
int main()
{
    char input[22];
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%s %s",list[i].add,list[i].pw);
    qsort(list,n,sizeof(sp),cmp);
    for (int i = 0; i < m; i++){
        scanf("%s",input);
        printf("%s\n",list[find(0,n-1,input)].pw);
    }
    return 0;
}
/*
c++ 해시맵풀이
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	map<string, string> site2password;

	for (int i = 0; i < N; i++)
	{
		string site, password;
		cin >> site >> password;

		site2password[site] = password;
	}

	for (int i = 0; i < M; i++)
	{
		string site;
		cin >> site;

		cout << site2password[site] << "\n";
	}

	return 0;
}

*/