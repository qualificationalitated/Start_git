#include<stdio.h>
#include<string.h>
int map[52][52],n,max=0;
int main()
{
    char s[52];
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            map[i][j]=3;
    for (int i = 0; i < n; i++){
        scanf("%s",s);
        for (int j = 0; j < n; j++)
            if(s[j]=='Y')
                map[i][j]=1;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(map[i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
    for (int i = 0; i < n; i++){
        int cnt=0;
        for (int j = 0; j < n; j++)
            if(i!=j&&(map[i][j]==1||map[i][j]==2))
                cnt++;
        if(max<cnt)
            max=cnt;
    }
    printf("%d",max);
    return 0;
}
/**
 * @brief 플로이드 마샬은 처음 써보는 것에 대하여..
 * 플로이드 마샬 알고리즘을 활용해 문제를 풀었다.
 * n^3 만큼의 시간복잡도를 가진다.
 * 우선 배열의 
 * i,j 위치에 도달 할 때, k를 거치고 가면 빠를경우를 찾아 갱신해준다.
 * 본 문제에서는 두 다리 걸쳐서 친구를 찾고싶으므로, 친구간 거리가 2 이하인 경우만 찾으면 된다.
 */