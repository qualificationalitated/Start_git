#include <stdio.h>
int main()
{
    int mStart, nEnd, min = 10001, sum = 0;
    int sosu[10001] = {
        0,
    };
    scanf("%d %d", &mStart, &nEnd);
    if(mStart==1)
    mStart=2;
    for (int i = 2; i <= nEnd / 2; i++)
    {
        if (!sosu[i])
            for (int j = 2; j <= nEnd / i; j++)
            {
                sosu[i * j] = 1;
            }
    }
    for (int i = mStart; i <= nEnd; i++)
    {
        if (sosu[i] == 0)
        {
            sum += i;
            if (min > i)
                min = i;
        }
    }
    if (!sum)
        printf("-1");
    else
        printf("%d\n%d\n", sum, min);
    return 0;
}