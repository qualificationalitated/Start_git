#include <stdio.h>
int main()
{
    int destination, i, c = 0;
    scanf("%d", &destination);
    if (destination != 1)
    {
        while (destination-1 > 0)
        {
            c++;
            destination -= 6 * c;
        }
        printf("%d", c + 1);
    }
    else
        printf("1");
    return 0;
}