#include<stdio.h>
#include<stdlib.h>
char code[17],answer[17];
int l,c;
int cmp(const void *a, const void *b)
{
    return *(char*)a-*(char*)b;
}
int find(int loc,int len,int mO,int jA)
{
    // 출력
    if(len==l&&1<=mO&&2<=jA){
        for (int p = 0; p < l; p++)
            printf("%c",answer[p]);
        printf("\n");
        return 0;
    }
    // 문자열 만들기
    for (int i = loc; i < c; i++){
        char jm=code[i];
        if(jm=='a'||jm=='e'||jm=='i'||jm=='o'||jm=='u'){
            answer[len]=jm;
            find(i+1,len+1,mO+1,jA);
        }
        else{
            answer[len]=jm;
            find(i+1,len+1,mO,jA+1);
        }
    }
    return 0;
}
int main()
{
    int cnt=0;
    char temp;
    scanf("%d%d",&l,&c);
    //암호 문자 입력
    while(1){
        scanf("%c",&temp);
        if(cnt==c)
            break;
        if(97<=temp&&temp<=122)
            code[cnt++]=temp;
    }
    // 문제 조건 중 "순서대로 넣어라"를 위해 정렬함
    qsort(code,c,sizeof(char),cmp);
    find(0,0,0,0);
    return 0;
}