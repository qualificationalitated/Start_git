# 2751번

```c
#include <stdlib.h>
#include <stdio.h>
int compare(const void *p, const void *q)
{
    if(*(int *)p<*(int *)q)
        return -1;
    if(*(int *)q<*(int *)p)
        return 1;
    return 0;
}
int main()
{
    int n;
    int *a;
    scanf("%d",&n);
    a=(int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),compare);
    for (int j = 0; j < n; ++j) {
        printf("%d\n",a[j]);
    }
    free(a);
    return 0;
}
```

