#include <stdio.h>
int main()
{
    int n, m, min = 4001, max = -4001;
    int countList = 0, sumList = 0, manyNum, centerNum, centerNumCheck = 1, isThereCountlist = 0;
    double sum = 0;
    int list[8002] = {0,};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        list[m + 4000]++; // 정렬용 배열
        sum += m;         // 평균
        if (max < m)      //범위
            max = m;
        if (min > m)
            min = m;
    }
    printf("%.0lf\n", sum / n);
    for (int i = 0; i <= 8001; i++)
    {
        sumList += list[i];
        if (countList <= list[i] && list[i] != 0)
        { //최빈
            if (countList == list[i] && isThereCountlist)
            {
                countList = list[i];
                manyNum = i - 4000;
                isThereCountlist = 0;
            }
            else if (countList < list[i])
            {
                countList = list[i];
                manyNum = i - 4000;
                isThereCountlist = 1;
            }
        }
        if (centerNumCheck && (n / 2 + 1) <= sumList)
        { //중앙
            centerNum = i - 4000;
            centerNumCheck = 0;
        }
    }
    printf("%d\n%d\n", centerNum, manyNum);
    printf("%d", max - min);
    return 0;
}