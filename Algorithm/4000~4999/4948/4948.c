#include <stdio.h>
int main()
{
    int n, count = 0;
    long sosu[246913] = {
        0,
    };
    long gaesu[246913] = {
        0,
    };
    gaesu[1] = 0;
    for (int i = 2; i <= 246912; i++)
    {
        gaesu[i] = count;
        if (!sosu[i])
        {
            count++;
            gaesu[i] = count;
            for (int j = 2; j <= 246912 / i; j++)
            {
                sosu[i * j] = 1;
            }
        }
    }
    while (1)
    {
        scanf("%d", &n);
        if (!n)
        {
            return 0;
        }
        printf("%ld\n", gaesu[2 * n] - gaesu[n]);
    }
    return 0;
}