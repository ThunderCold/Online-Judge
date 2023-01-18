#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n, t, x;
	bool f = 0;
	while (cin >> n >> t)
	{
		map<int, vector<int>> ma;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			ma[x].push_back(i + 1);
		}
		for (auto it = ma.begin(); it != ma.end(); it++)
		{
			if (ma.count(t - (it->first)) )
			{
				if (it->first != t - (it->first))
				{
					int a[2] = {it->second[0], ma[t - (it->first)][0]};
					sort(a, a + 2);
					for (auto i : a) cout << i << " ";
					f = 1;
					break;
				}
				else if (it->second.size() > 1)
				{
					cout << it->second[0] << " " << it->second[1];
					f = 1;
					break;
				}
			}
		}
		if (!f)
		{
			cout << "IMPOSSIBLE";
		}
	}

	return 0;
}