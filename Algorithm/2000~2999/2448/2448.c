#include<stdio.h>
#include<string.h>
char rec[3][5]={{' ',' ','*',' ',' '},
                {' ','*',' ','*',' '},
                {'*','*','*','*','*'}};
char map[3100][6200];
int makeRec(int n,int row, int column){
    if(n==3)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                map[row+i][column+j]=rec[i][j];
    else{
        int x=n/2;
        makeRec(x,row,column+x);
        makeRec(x,row+x,column);
        makeRec(x,row+x,column+x*2);
    }
    return 0;
}
int main()
{
    int n;
    memset(map,' ',3100*6200*sizeof(char));
    scanf("%d",&n);
    makeRec(n,0,0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2*n-1; j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
    return 0;
}