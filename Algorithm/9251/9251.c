#include<stdio.h>
#include<string.h>
int len[1002][1002];
int main()
{
    char a[1002],b[1002];
    scanf("%s %s",a,b);
    for (int i = 1; i <= strlen(a); i++)
    {
        for (int j = 1; j <= strlen(b); j++)
        {
            if(a[i-1]==b[j-1])
                len[i][j]=len[i-1][j-1]+1;
            else{
                len[i][j]=len[i][j-1];
                if(len[i][j-1]<len[i-1][j])
                    len[i][j]=len[i-1][j];
            }
        }
    }
    printf("%d",len[strlen(a)][strlen(b)]);
    return 0;
}
/**
 * @brief 풀이
 * 답을 찾고자,두 문자열의 부분수열별로 비교를 하며, 이 때 두 부분 수열의 가장 긴 공통 부분수열을 찾는다.
 * 2차원 배열을 활용하여 비교를 실시한다.
 * ACAYKP
 * CAPCAK
 * 와 같은 입력에서
 * A - C | CA | CAP | CAPC | CAPCA | CAPCAK
 * AC - C | CA | CAP | CAPC | CAPCA | CAPCAK
 * ...
 * ACAYKP - C | CA | CAP | CAPC | CAPCA | CAPCAK
 * 순으로 비교를 실시하며, 이를 2차원 상에서는 
 * if(a[i-1]==b[j-1])
                len[i][j]=len[i-1][j-1]+1;
            else{
                len[i][j]=len[i][j-1];
                if(len[i][j-1]<len[i-1][j])
                    len[i][j]=len[i-1][j];
            }
 * 위와같은 규칙을 바탕으로 기록하게 된다.
 * 비교할 때의 두 값이 동일할경우, 두 값이 없던 상태(왼쪽 대각선 위)에서 새로운 값이 들어와 길이가 +1 된것이므로, 왼쪽 대각선 위 값 +1 값을 현제의 값으로 설정한다
 * 아닐경우, 두 문자열 부분의 부분수열의 최대부분을 왼쪽과 위 둘중 큰값으로 설정한다.
 */