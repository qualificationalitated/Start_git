#include<stdio.h>
#define LIM 52
int knowFact[LIM]={0,}; // 진실을 아는 사람 명단
int partyList[LIM][LIM]={0,}; // 파티에 참여한 사람 명단
int headCount[LIM]; //파티에 참여한 사람 수
int main()
{
    int n,m,l,p,ans=0;
    // 입력
    scanf("%d %d %d",&n,&m,&l);
    for (int i = 0; i < l; i++){
        scanf("%d",&p);
        knowFact[p]=1;
    }
    for (int f = 0; f < m; f++){
        scanf("%d",&headCount[f]);
        for (int i = 0; i < headCount[f]; i++){
            scanf("%d",&p);
            partyList[f][i]=p;
        }
    }
    // 사실만 말해야할 사람들 찾기
    while(1){
        int newKnow=0;
        // 모든 파티를 확인하며, 파티에 참여한 사람중 사실을 아는사람이 있으면 체크
        for (int i = 0; i < m; i++){
            int know=0;
            for (int j = 0; j < headCount[i]; j++)
                if(knowFact[partyList[i][j]])
                    know=1;
            // 참여인원중 사실을 아는 사람이 있다면, 참여인원 전체에게 사실을 말함
            if(know)
                for(int j = 0; j < headCount[i]; j++)
                    // 이 중, 새롭게 사실을 알게된 사람이 있다면 체크
                    if(!knowFact[partyList[i][j]]){
                        knowFact[partyList[i][j]]=1;
                        newKnow=1;
                    }
        }
        // 새롭게 사실을 알게되는 사람이 없을때까지 확인
        if(!newKnow) break;
    }
    // 사실을 아는 사람이 없는 파티는 과장되게 말한다
    for (int i = 0; i < m; i++){
        int factos=1;
        for (int j = 0; j < headCount[i]; j++)
            if(knowFact[partyList[i][j]])
                factos=0;
        ans+=factos;
    }
    printf("%d",ans);
    return 0;
}