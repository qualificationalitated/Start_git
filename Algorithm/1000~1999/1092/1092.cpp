#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isMoveable(vector<int> crains, vector<int> boxes, int size)
{
	if (size * crains.size() < boxes.size())
		return false;
	bool result = true;
	for (int i = 0; i < boxes.size(); i++)
	{
		if (crains[i / size] < boxes[i])
		{
			result = false;
			break;
		}
	}
	return result;
}
int main()
{
	int n, m;
	vector<int> crain_weis, box_weis;
	cin >> n;
	crain_weis.resize(n);
	for (int i = 0; i < n; i++)
		cin >> crain_weis[i];
	sort(crain_weis.begin(), crain_weis.end(), greater<int>());
	cin >> m;
	box_weis.resize(m);
	for (int i = 0; i < m; i++)
		cin >> box_weis[i];
	sort(box_weis.begin(), box_weis.end(), greater<int>());

	if (crain_weis[0] < box_weis[0])
		cout << "-1";
	else
	{
		bool is_div = box_weis.size() % crain_weis.size();
		int head = box_weis.size() / crain_weis.size() + is_div, tail = m;
		// 구분 구간 이진탐색
		while (head < tail)
		{
			int mid = (head + tail) / 2;
			bool result = isMoveable(crain_weis, box_weis, mid);
			// cout<<head<<" "<<mid<<" "<<tail<<"-"<<result<<"\n";
			if (result)
				tail = mid;
			else
				head = mid + 1;
		}
		cout << head;
	}
	return 0;
}