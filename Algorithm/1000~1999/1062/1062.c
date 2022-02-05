#include<stdio.h>
#include<string.h>
int n,m;
char words[51][17],midWords[51][17];
int newAlpIdx[26]={0,},newAlpList[26]={0,},newAlpCnt=0;
int selectedAlp[26];
int find(){
    int result=0;
    for (int i = 0; i < n; i++)
    {
        int len=strlen(midWords[i]),teachable=1;
        if(len)
        for (int j = 0; j < len; j++){
                char x=midWords[i][j];
                if(x!='a'&&x!='n'&&x!='t'&&x!='i'&&x!='c')
                    if(!selectedAlp[x-'a'])
                        teachable=0;
            }
        result+=teachable;
    }
    return result;
}
int solve(int x,int l){
    int ans=0,selectable=0;
    selectable=m-5>newAlpCnt?newAlpCnt:m-5;
    if(x==selectable)
        return find();
    for (int i = l; i < newAlpCnt; i++){
        int tmp=newAlpList[i],r;
        if(newAlpIdx[tmp]&&(!selectedAlp[tmp])){
            selectedAlp[tmp]=1;
            r=solve(x+1,i);
            ans=r>ans?r:ans;
            selectedAlp[tmp]=0;
        }
    }
    return ans;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++){
        scanf("%s",words[i]);
        for (int j = 4; j < strlen(words[i])-4; j++){
            char c=words[i][j];
            midWords[i][j-4]=c;
            if(c!='a'&&c!='n'&&c!='t'&&c!='i'&&c!='c'){
                if(!newAlpIdx[c-'a']){
                    newAlpIdx[c-'a']=1;
                    newAlpList[newAlpCnt++]=c-'a';
                }
            }
        }
    }
    m<5?printf("0"):printf("%d",solve(0,0));
    return 0;
}