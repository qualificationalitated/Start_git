#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define WORK 10002
using namespace std;
int workTime[WORK], prevWorkCnt[WORK];
int dp[WORK];
vector<int> workPriority[WORK];
queue<int> workList;
void setMaxTimeINdpArray()
{
    while (!workList.empty())
    {
        int nowWork = workList.front();
        workList.pop();
        for (int i = 0; i < workPriority[nowWork].size(); i++)
        {
            int nextWork = workPriority[nowWork][i];
            prevWorkCnt[nextWork]--;
            if (!prevWorkCnt[nextWork]){
                workList.push(nextWork);
            }
            dp[nextWork] = max(dp[nextWork], dp[nowWork] + workTime[nextWork]);
        }
    }
}
int main()
{
    int n, cnt, works, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &workTime[i], &cnt);
        prevWorkCnt[i] = cnt;
        if (!cnt)
        {
            workList.push(i);
            dp[i] = workTime[i];
        }
        while (cnt--)
        {
            scanf("%d", &works);
            workPriority[works].push_back(i);
        }
    }
    setMaxTimeINdpArray();
    for (int i = 1; i <= n; i++)
    {
        ans = ans > dp[i] ? ans : dp[i];
        
    }
    printf("%d", ans);
    return 0;
}
