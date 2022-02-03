#include <stdio.h>
int sixCheck(int n)
{
    int count=0,check=0;
    while(n!=0){
        if (n % 10 == 6){
            if (check){
                count++;
            }
            else{
                count = 1;
            }
            check = 1;
        }
        else{
            count = 0;
            check = 0;
        }
        if (count == 3)
            return 1;
        n = n / 10;
    }
    return 0;
}
int main()
{
    int sixList[10001] = {0,};
    int n, count = 0,i=666;
    scanf("%d", &n);
    while(count<10001)
    {
        if(sixCheck(i++))
        {   
            sixList[count++] = i-1;
        }
    }
    printf("%d", sixList[n-1]);
    return 0;
}