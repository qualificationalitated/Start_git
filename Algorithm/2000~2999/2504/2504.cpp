#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char s[32],stack[32];
    int top=0;
    long long int temp=1,ans=0;
    bool check=true;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('||s[i]=='['){
            stack[++top]=s[i];
            if(s[i]=='(')
                temp*=2;
            if(s[i]=='[')
                temp*=3;
        }
        else if(s[i]==')'){
            if( (!top) || stack[top]!='(' ){
                check=false;
                break;
            }
            top--;
            if(s[i-1]=='(')
                ans+=temp;
            temp/=2;
        }
        else if(s[i]==']'){
            if( (!top) || stack[top]!='[' ){
                check=false;
                break;
            }
            top--;
            if(s[i-1]=='[')
                ans+=temp;
            temp/=3;
        }
    }
    if(check==false || top)
        printf("0");
    else
        printf("%lld",ans);
    return 0;
}