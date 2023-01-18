#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n;
	while (cin >> n)
	{
		int a[n];
		for (auto &i : a) cin >> i;
		int ans = 1, abd = -1;
		map<int, int> ma;
		int dp[n];
		for (int i = 0; i < n; i++)
		{
			if (ma.find(a[i]) == ma.end() || abd > ma[a[i]]) //not found
			{
				ma[a[i]] = i;
				if (i == 0) dp[i] = 1;
				else dp[i] = dp[i - 1] + 1;
				ans = max(ans, dp[i]);
			}
			else
			{
				dp[i] = dp[i - 1] + 1 - (ma[a[i]] - abd);
				abd = ma[a[i]];
				ma[a[i]] = i;
				ans = max(ans, dp[i]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}