#include <stdio.h>
#include <string.h>
int main()
{
    char a, answer;
    int checklist[26] = {0,},max = 0, same = 0;
    while (a != '\n') // 엔터 입력 전까지 계속 문자 입력
    {
        scanf("%c", &a);
        if (a - 96 > 0)
        {                        // 대소문자 분별
            checklist[a - 97]++; //소문자
        }
        else
            checklist[a - 65]++; //대문자
    }
    for (int j = 0; j < 26; j++)
    {
        if (max < checklist[j])
        {
            same = 0;
            max = checklist[j];
            answer = 65 + j;
        }
        else if (!(max - checklist[j]))
        {
            same = 1;
        }
    }
    if (!same)
        printf("%c", answer);
    else
        printf("?");
    return 0;
}