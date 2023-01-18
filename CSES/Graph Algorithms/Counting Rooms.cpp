#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int a[1005][1005];
int n, m;

void sol(int x, int y)
{
	a[x][y] = 1;
	if (x > 0 && a[x - 1][y] == 0) sol(x - 1, y);
	if (y > 0 && a[x][y - 1] == 0) sol(x, y - 1);
	if (y < m - 1 && a[x][y + 1] == 0) sol(x, y + 1);
	if (x < n - 1 && a[x + 1][y] == 0) sol(x + 1, y);
}

int main() {
	_
	string s;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			for (int j = 0; j < m; j++)
			{
				if (s[j] == '#') a[i][j] = -1;
				else if (s[j] == '.') a[i][j] = 0;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0)
				{
					ans++;
					sol(i, j);
				}
			}
		}
		cout << ans;
	}

	return 0;
}