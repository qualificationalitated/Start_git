#include <stdio.h>
#include <string.h>
char cmd[100002],c;
int n,num=0,list[100002];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int rot=1,head=0,top=0,error=0;
        scanf("%s",cmd);
        scanf("%d",&n);
        // get number list
        while (1){
            scanf("%c", &c);
            if (48<=c&&c<=57)
                num=num*10+(c-'0');
            else if(c==','||c==']'){
                //if number is commanded
                if(num){
                    list[top++]=num;
                    num=0;
                }
                if (c==']')
                    break;
            }
        }
        // check command
        for (int i=0;i<strlen(cmd);i++){
            if(cmd[i]=='R')
                rot*=-1; // 1-forward -1-reverse
            else{
                if (head >= top){//if D command is not possble
                    printf("error");
                    error = 1;
                    break;
                }
                //pop
                if (rot==1)
                    head++;
                else
                    top--;
            }
        }
        if (!error){
            printf("[");
            if(head<top)// deal with some special cases like R 0 [] 
            if (rot==1){
                for(int i=head;i<top-1;i++)
                    printf("%d,",list[i]);
                printf("%d",list[top-1]);
            }
            else{
                for (int i=top-1;i>head;i--)
                    printf("%d,",list[i]);
                printf("%d",list[head]);
            }
            printf("]");
        }
        printf("\n");
    }
    return 0;
}