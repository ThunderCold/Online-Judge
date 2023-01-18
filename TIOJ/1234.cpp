#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
	io_optimized
	int n;
	while (cin >> n)
	{
		map<double, pair<int, int>> ma;
		for (double i = n; i >= 2; i--) //分母
		{
			for (double j = i - 1; j >= 1; j--) //分子
			{
				if (__gcd(int(j), int(i)) == 1)
				{
					pair<double, double> p;
					p = make_pair(j, i);
					ma[j / i] = p;
				}
			}
		}
		cout << ma.size() << "\n";
		auto it = ma.begin();
		if (ma.size() < n)
		{
			cout << int(it->second.first) << "/" << int(it->second.second) << "\n";
			continue;
		}
		int k = 1;
		while (k != n)
		{
			it++;
			k++;
		}
		cout << int(it->second.first) << "/" << int(it->second.second) << "\n";
	}

	return 0;
}
