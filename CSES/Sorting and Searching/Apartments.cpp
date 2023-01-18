#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int a[n], b[m];
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;
		sort(a, a + n);
		sort(b, b + m);
		int x = 0, y = 0, ans = 0;
		while (x < n && y < m)
		{
			if (b[y] - k <= a[x] && a[x] <= b[y] + k)
			{
				ans++;
				x++;
				y++;
			}
			else if (b[y] - k > a[x])
			{
				x++;
			}
			else
			{
				y++;
			}
		}
		cout << ans;
	}

	return 0;
}