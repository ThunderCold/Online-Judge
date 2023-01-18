#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define mp make_pair

int main() {
	_
	int n, x, y;
	while (cin >> n)
	{
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v.push_back(mp(x, 1));
			v.push_back(mp(y, -1));
		}
		sort(v.begin(), v.end());
		int cur = 0, ans = 0;
		for (auto i : v)
		{
			cur += i.second;
			ans = max(ans, cur);
		}
		cout << ans;
	}

	return 0;
}