#include <iostream>
using namespace std;
int main()
{
	int n, k, ans = 0;
	string table;
	cin >> n >> k >> table;
	bool eaten[table.size() + 1];
	for (int i = 0; i < table.size(); i++) eaten[i] = false;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i] == 'P')
		{
			int st = 0 > i - k ? 0 : i - k;
			int ed = n - 1 < i + k ? n - 1 : i + k;
			for (int j = st; j <= ed; j++)
			{
				if (table[j] == 'H' && eaten[j] == false)
				{
					eaten[j] = true;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}