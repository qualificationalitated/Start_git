#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct reco{
	int stu_id, rec_count, rec_time;
};
bool cmpA(const reco a, const reco b){
	if(a.rec_count == b.rec_count)
		return a.rec_time<b.rec_time;
	return a.rec_count<b.rec_count;
}
bool cmpB(const reco a, const reco b){
	return a.stu_id<b.stu_id;
}
int main(){
	int n,rec,student; // 사진틀의 수, 추천 수, 추천 번호
	vector<reco> can_list;
	cin>>n>>rec;
	for(int i=0;i<rec;i++){
		cin>>student;
		if(can_list.size()<n){
			bool is_first = true;
			for(int idx=0;idx<can_list.size();idx++){
				if(can_list[idx].stu_id == student){
					is_first = false;
					can_list[idx].rec_count++;
				}
			}
			if(is_first)
				can_list.push_back({student,1,i});
		}
		else{
			bool is_first = true;
			for(int idx=0;idx<can_list.size();idx++){
				if(can_list[idx].stu_id == student){
					is_first = false;
					can_list[idx].rec_count++;
				}
			}
			if(is_first){
			sort(can_list.begin(),can_list.end(),cmpA);
			can_list[0] = {student,1,i};
			}
		}
	}
	sort(can_list.begin(),can_list.end(),cmpB);
	for (auto i : can_list)
		cout<<i.stu_id<<" ";
	
	return 0;
}