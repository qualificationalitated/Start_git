#include<stdio.h>
int map[2][100002]={0,},n,t,ans,temp;
inline int max(int x,int y){
    return x>y?x:y;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                scanf("%d",&map[i][j]);
        if(n==1)
            ans=max(map[0][0],map[1][0]);
        else{
            map[1][1]+=map[0][0];
            map[0][1]+=map[1][0];
            ans=max(map[0][1],map[1][1]);
            for (int i = 2; i < n; i++){
                map[1][i]+=max(map[0][i-1],map[0][i-2]);
                map[0][i]+=max(map[1][i-1],map[1][i-2]);
                temp=max(map[0][i],map[1][i]);
                if(ans<temp)
                    ans=temp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}