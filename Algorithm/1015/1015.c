#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main()
{
    int n,a[51],b[51],v[51]={0,},i,j;
    // 입력-원소의 갯수 및 원소 입력
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
        //복사용 배열 B에 내용 복사
        b[i]=a[i];
    }
    //B 배열 정렬
    qsort(b,n,sizeof(int),cmp);
    //원래 원소들과 정렬된 B 배열의 원소를 비교, 이동한 위치를 파악
    //v 배열을 통해 같은 데이터가 있을 경우 값의 이동된 위치를 잘못 파악할 경우를 배제
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if(a[i]==b[j]&&v[j]==0)
            {
                printf("%d ",j);
                v[j]=1;
                break;
            }
    return 0;
}