#include<iostream>
#include<algorithm>
#define MLEN 200001
using namespace std;
int ss[MLEN]={0,},jyu[MLEN]={0,},min=MLEN;
int find_ob_count_jyu(int st,int ed,int target){
    while(st<=ed){
        int mid=(st+ed)/2;
        if(jyu[mid]<=target) // 등호 주의!
            ed=mid-1;
        else
            st=mid+1;
    }
    if(target==jyu[ed])
        return ed;
    else
        return ed+1;
}
int find_ob_count_ss(int st,int ed,int target){
    while(st<=ed){
        int mid=(st+ed)/2;
        if(ss[mid]<target)
            ed=mid-1;
        else
            st=mid+1;
    }
    return ed+1;
}
int main(){
    int n,h,ob;
    int min=MLEN,count=1;
    cin>>n>>h;
    for (int i = 0; i < n/2; i++) // 나머지 0이면 석순, 1이면 종유석
        cin>>ss[i]>>jyu[i];
    sort(ss,ss+n/2,greater<int>()); // 내림차순 정렬
    sort(jyu,jyu+n/2,greater<int>()); // 내림차순 정렬
    for (int i = 1; i <= h; i++)
    {
        int obCount = find_ob_count_ss(0,n/2,i) + find_ob_count_jyu(0,n/2,h-i);
        if(obCount<min){
            min=obCount;
            count=1;
        }
        else if(obCount==min)
            count++;
    }
    cout<<min<<" "<<count;
    return 0;
}