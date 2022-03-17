/**
 * @brief 15684_사다리조작 풀이
 * 초기 사다리 상태를 배열로 입력받고, 사다리가 없는 부분의 좌표를 후보 구조체 배열에 저장
 * 자신에서 출발해서 자신을 가리키기위해선 자신의 사다리에 연결된 통로가 짝수개여야하므로, 각 사다리별 통로의 갯수를 구해 최소 통로의 갯수를 구한다
 * 만일 추가해야할 최소 통로갯수가 3 이상이면 일단 거르고,
 * 아니면 후보지를 고른다
 * 여기서도 후보지가 3군데 이상 골라진다면 거르고
 * 마지막 번호까지 도달하면서 후보지 3군대를 골랐으면 모든 경로가 올바르게 가는지 쳌크한 다음
 * 간다! 하면 필요 통로수를 최소로 갱신한다
 */
#include<stdio.h>
#define WID 12
#define HEI 32
typedef struct{
    int loc,h;
}sdr;

sdr huboList[300];
int huboCnt=0;
int sadari[WID][HEI]={0,};
int n,m,h,ans=4;

int checkPath(){
    int check=1;
    for(int i=1;i<=n;i++){
        int now=i;
        for(int j=1;j<=h;j++){
            if(sadari[now][j])
                now++;
            else if(sadari[now-1][j])
                now--;
        }
        if(now!=i){
            check=0;
            break;
        }
    }
    return check;
}
int selectHubo(int x,int cnt){
    if(cnt>3)
        return 0;
    if(x>=huboCnt){
        if(checkPath())
            ans=ans>cnt?cnt:ans;
        return 0;
    }
    int loc=huboList[x].loc;
    int h=huboList[x].h;
    sadari[loc][h]=1;
    selectHubo(x+1,cnt+1);
    sadari[loc][h]=0;
    selectHubo(x+1,cnt);
    return 0;
}
int main(){
    int nono=0,needSadari=0,a,b;
    scanf("%d %d %d",&n,&m,&h);
    while(m--){
        scanf("%d %d",&a,&b);
        if(sadari[b][a])
            nono=1;
        sadari[b][a]=1;
    }
    for(int i=1;i<n;i++){
        int placed=0;
        for(int j=1;j<=h;j++){
            if(sadari[i][j])
                placed++;
            else{
                huboList[huboCnt].loc=i;
                huboList[huboCnt].h=j;
                huboCnt++;
            }
        }
        needSadari+=(placed%2);
    }
    if(nono||needSadari>3)
        printf("-1");
    else{
        selectHubo(0,0);
        if(ans==4)
            printf("-1");
        else
            printf("%d",ans);
    }
    return 0;
}