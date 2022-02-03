#include<stdio.h>
#include<string.h>
int main()
{
    int n=0,m;
    char str[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %[^\n]s",&m,str);
        for (int j = 0; j < strlen(str); j++){
            for(int k=0;k<m;k++){
                printf("%c",str[j]);
            }    
        }
        printf("\n");
    }
    return 0;
}