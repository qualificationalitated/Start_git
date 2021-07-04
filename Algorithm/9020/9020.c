#include <stdio.h>
int main()
{
    int m;
    int n;
    int countO = 0,countT=0, checkResult = 0;
    int map[10001] = {
        0,
    };
    int checkMap[10001] = {
        0,
    };
    //1. 소수 맵 구성
    {
        for (int i = 2; i <= 100; i++)
        {
            for (int j = i; j <= 10000 / i; j++)
            {
                map[i * j] = 1;
            }
        }
        for (int i = 2; i <= 10000; i++)
        {
            if (!map[i])
                checkMap[++countO] = i;
        }
    }
    //2. 판별
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        countO = 0; //소수 맵에서 중간값의 위치 찾기용
        checkResult = 0;
        scanf("%d", &m);
        while(checkMap[countO]<m/2)
        {
            countO++;   
        }
        for (int j = countO; j >=0; j--)
        {
            countT=j;
            while(m>checkMap[j] + checkMap[countT])
            {
                countT++;
            }
            if (m == checkMap[j] + checkMap[countT])
            {
                printf("%d %d\n", checkMap[j], checkMap[countT]);
                break;
            }
        }
    }
    return 0;
}
/*
1. 소수 맵 구성/10000까지의 소수를 배열로 저장
2. 두 소수간 합계가 적어야한다 -> 입력값은 짝수이므로, 입력값의 절반부터 정답찾기 시작.
3. 중간값을 찾았다면, 찾은 위치에서부터 하나씩 작은 소수로 내려가며 합계를 구함.
*/