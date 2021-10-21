#include<stdio.h>
int map[2][100002],n,max=0;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        map[0][1]=0;
        map[1][1]=0;
        scanf("%d",&n);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++){
                scanf("%d",&map[i][j]);
                if(max<map[i][j])
                    max=map[i][j];
            }
        map[1][1]+=map[0][0];
        map[0][1]+=map[1][0];
        max=map[0][1];
        if(max<map[1][1])
            max=map[1][1];
        for (int i = 2; i < n; i++){
            int temp=map[0][i-1];
            if(temp<map[0][i-2])
                temp=map[0][i-2];
            map[1][i]+=temp;

            temp=map[1][i-1];
            if(temp<map[1][i-2])
                temp=map[1][i-2];
            map[0][i]+=temp;
            for (int j = 0; j < 2; j++)
                if(max<map[j][i])
                    max=map[j][i];
        }
        printf("%d\n",max);
    }
    return 0;
}