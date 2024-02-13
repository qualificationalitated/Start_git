#include <string>
#include <vector>

using namespace std;

bool visited[9];
int recursive(vector<vector<int>> dungeons,int currK,int cnt,int *ans){
    if(*ans < cnt) *ans = cnt;
    for(int i=0;i<dungeons.size();i++){
        if(visited[i] == false && currK >= dungeons[i][0]){
            visited[i] = true;
            recursive(dungeons,currK - dungeons[i][1],cnt+1,ans);
            visited[i] = false;
        }
    }
    return 0;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    recursive(dungeons, k, 0,&answer);
    return answer;
}