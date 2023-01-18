#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main () {
	io_optimized
	int q, n, m;
	string s;
	while (cin >> q >> n >> m)
	{
		char c[m + 1][n];
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		while (q--)
		{
			cin >> s;
			for (int i = 0; i < n; i++)
			{
				c[0][i] = s[i];
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					c[i + 1][a[j] - 1] = c[i][j];
				}
			}
			for (int i = 0; i < n; i++)
			{
				cout << c[m][i];
			}
			cout << "\n";
		}
	}

	return 0;
}
