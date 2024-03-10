#include<iostream>
using namespace std;
int get_right_dist(int x,int y,int wid,int hei){
    int ans=0;
    switch(x) // direction
    {
    case 1: // north
        ans = y;
        break;
    case 2: // south
        ans = 2*wid+hei-y;
        break;
    case 3: // west
        ans = 2*wid+2*hei-y;
        break;
    case 4: // east
        ans = wid+y;
        break;
    default:
        break;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int wid,hei,cnt,ans=0,x,y;
    int st_dist[101],dg_dist=0;
    cin>>wid>>hei>>cnt;
    for(int i=0;i<cnt;i++){
        cin>>x>>y;
        st_dist[i] = get_right_dist(x,y,wid,hei);
    }
    cin>>x>>y;
    dg_dist = get_right_dist(x,y,wid,hei);
    for (int i = 0; i < cnt; i++)
    {
        int rDistGap = abs(st_dist[i]-dg_dist);
        int lDistGap = 2*(wid+hei) - rDistGap;
        ans+=rDistGap>lDistGap?lDistGap:rDistGap;
    }
    cout<<ans;
    return 0;
}