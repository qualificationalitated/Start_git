#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int stdNum;
    int arr[1000][5],cnt[1000]={0,},stuCheck[1000];
    int max=0, maxIndex;
    scanf("%d",&stdNum);
    for(int i=0;i<stdNum;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<stdNum;i++){
        for(int j=0;j<1000;j++)
            stuCheck[j]=1;
        for(int j=0;j<stdNum;j++){
            for(int k=0;k<5;k++){
                if(i!=j && arr[i][k]==arr[j][k]){
                    cnt[i]+=stuCheck[j];
                    stuCheck[j]=0;
                }
            }
        }
    }
    for(int i=stdNum-1;i>=0;i--){
        if(max<=cnt[i]){
            max=cnt[i];
            maxIndex=i+1;
        }
    }
    printf("%d",maxIndex);
    return 0;
}