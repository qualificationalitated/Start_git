#include<stdio.h>
#include<string.h>
int main()
{
    char croatiaLan[8][4]={"c=","c-","dz=","d-","lj","nj","s=","z="};
    char input[101];
    int count=0,a=1;
    scanf("%s",input);
    count=strlen(input);
    while(strlen(input)){    
        for (int j = 0; j < 8; j++){
            if(!strncmp(input,croatiaLan[j],strlen(croatiaLan[j]))){
                a=strlen(croatiaLan[j]);
                count=count-strlen(croatiaLan[j])+1;
            }
        }
        for (int i = 0; i < strlen(input); i++){
            input[i]=input[i+a];
        }
        a=1;
    }
    printf("%d",count);
    return 0;
}