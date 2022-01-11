/**
 * @file 1717.c
 * @brief Union-find 알고리즘
 * 분리집합 문제, tree구조를 활용해 문제를 해결하였다.
 * 각 집합별로 자신의 부모 노드를 기억하는 배열을 활용한다.
 * 두 집합을 병합할 때, 부모노드를 찾아 올라가 나오는 루트가 다를 경우 이를 다른 집합이라고 판단하여 하나의 루트 아래에 다른 루트를 넣어준다.
 * 두 값이 같은 집합에 있는지 탐색할 때에도 각 집합의 루트가 동일한지 판단한다.
 */
#include<stdio.h>
int n,m,num[1000002]={0,};
int find(int x){
    if(x==num[x])
        return x;
    return num[x]=find(num[x]);
}
int main()
{
    for (int i = 0; i < 1000002; i++)
        num[i]=i;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        int cmd,a,b;
        scanf("%d%d%d",&cmd,&a,&b);
        int ra=find(a),rb=find(b);
        if(!cmd){ //합치기
            if(ra!=rb)
                num[rb]=ra;//입력값의 루트를 확인해서 넣어주기.
        }
        else {// 같은 집합인지 확인
            if(ra==rb)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}