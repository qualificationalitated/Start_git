#include <stdio.h>
int main()
{
    int n, m, temp;
    int sumJari, count = 0;
    scanf("%d", &n);
    temp = n;
    do
    {
        m = temp % 10;
        sumJari = 0;
        while (temp != 0)
        {
            sumJari += temp % 10;
            temp = temp / 10;
        }
        temp = (m * 10) + (sumJari % 10);
        count++;
    } while (temp != n);
    printf("%d", count);
    return 0;
}