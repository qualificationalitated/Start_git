#include<stdio.h>
#include<stdlib.h>
#define LIM 100003
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int shotPos[LIM];
int main()
{
    int m,n,l,ans=0;
    scanf("%d %d %d",&m,&n,&l);
    for (int i = 0; i < m; i++)
        scanf("%d",&shotPos[i]);
    qsort(shotPos,m,sizeof(int),cmp);
    while(n--){
        int x,y;
        scanf("%d %d",&x,&y);
        int head=0,tail=m-1;
        while(head<=tail){
            int mid=(head+tail)/2;
            int dist=abs(shotPos[mid]-x)+y;
            if(dist<=l){
                ans++;
                break;
            }
            else{
                if(x<shotPos[mid])
                    tail=mid-1;
                else
                    head=mid+1;
            }
        }
    }
    printf("%d",ans);
    return 0;
}