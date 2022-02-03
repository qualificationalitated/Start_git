#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct i{
    char s[52];
    int L;
} w;
w l[20001];
int wP(char *a,char *b,int L)
{
    for (int i = 0; i < L; i++)
        if(a[i]!=b[i])
            return a[i]-b[i];
    return 0;
}
int cmp(const void *a, const void *b)
{
    w *A=(w*)a;
    w *B=(w*)b;
    if(A->L!=B->L)
        return A->L-B->L;
    else if(A->L==B->L)
        return wP(A->s,B->s,A->L);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",l[i].s);
        l[i].L=strlen(l[i].s);
    }
    qsort(l,n,sizeof(w),cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",l[i].s);
        while(!strcmp(l[i].s,l[i+1].s))
            i++;
    }
    return 0;
}