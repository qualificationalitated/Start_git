#include<stdio.h>
int main()
{
    int n;
    int numberList[42]={0,};
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&n);
        numberList[n%42]=1;
    }
    printf("%d",numberList[0]+numberList[1]+numberList[2]+numberList[3]+numberList[4]+numberList[5]+numberList[6]+numberList[7]+numberList[8]+numberList[9]+numberList[10]+numberList[11]+numberList[12]+numberList[13]+numberList[14]+numberList[15]+numberList[16]+numberList[17]+numberList[18]+numberList[19]+numberList[20]+numberList[21]+numberList[22]+numberList[23]+numberList[24]+numberList[25]+numberList[26]+numberList[27]+numberList[28]+numberList[29]+numberList[30]+numberList[31]+numberList[32]+numberList[33]+numberList[34]+numberList[35]+numberList[36]+numberList[37]+numberList[38]+numberList[39]+numberList[40]+numberList[41]);
    return 0;
}