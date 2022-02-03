#include <stdio.h>
long long map[33][33];
int main() {
    int n;
    for (int w = 0; w <= 30; w++)
        for (int h = 0; h <= w; h++)
            if(!h) 
                map[w][h]=1;
            else 
                map[w][h]=map[w-1][h]+map[w][h-1];
    while (1) {
        scanf("%d",&n);
        if(!n)
            return 0;
        printf("%lld\n",map[n][n]);
    }
    return 0;
}