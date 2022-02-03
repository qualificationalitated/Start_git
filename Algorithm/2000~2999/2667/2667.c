//단지번호 붙이기
#include<stdio.h>
#include<stdlib.h>
char map[26][28];
int n,visited[26][26],nx[4]={1,-1,0,0},ny[4]={0,0,1,-1},cnt;
int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}
int find(int x,int y)
{
    int nextx,nexty;
    for (int i = 0; i < 4; i++)
    {
        nextx=x+nx[i];
        nexty=y+ny[i];
        if(nextx>=0&&nextx<n&&nexty>=0&&nexty<n&&map[nextx][nexty]=='1'&&visited[nextx][nexty]==0)
        {
            visited[nextx][nexty]=1;
            cnt++;
            find(nextx,nexty);
        }
    }
    return 0;
}
int main()
{
    int arr[700]={0,},top=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%s",map[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(map[i][j]=='1'&&visited[i][j]==0){
                cnt=1;
                visited[i][j]=1;
                find(i,j);
                arr[top++]=cnt;
            }
    qsort(arr,top,sizeof(int),cmp);
    printf("%d\n",top);
    for (int i = 0; i < top; i++)
        printf("%d\n",arr[i]);
    return 0;
}