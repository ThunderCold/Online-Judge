#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n, k;
	while (cin >> n >> k)
	{
		int a[n], ch[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			ch[i] = 1;
		}
		sort(a, a + n);
		int x = 0, y = n - 1, ans = 0;
		while (x < y)
		{
			if (a[x] + a[y] <= k)
			{
				ans++;
				ch[x] = ch[y] = 0;
				x++;
				y--;
			}
			else
			{
				y--;
			}
		}
		for (int i = 0; i < n; i++)
		{
			ans += ch[i];
		}
		cout << ans;
	}

	return 0;
}