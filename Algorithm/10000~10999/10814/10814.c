#include<stdio.h>
#include<stdlib.h>
typedef struct privacy{
    int age,number;
    char name[103];
}pcy;
int cmp(const void *a,const void *b)
{
    pcy *p1=(pcy*)a;
    pcy *p2=(pcy*)b;
    if(p1->age==p2->age)
        return p1->number-p2->number;
    else
        return p1->age-p2->age;
}
int main()
{
    int n;
    pcy *list;
    scanf("%d",&n);
    list=(pcy *)malloc(sizeof(pcy)*n);
    for (int i = 0; i < n; i++){
        scanf("%d %s",&list[i].age,list[i].name);
        list[i].number=i;
    }
    qsort(list,n,sizeof(pcy),cmp);
    for (int i = 0; i < n; i++)
        printf("%d %s\n",list[i].age,list[i].name);
    
    return 0;
}