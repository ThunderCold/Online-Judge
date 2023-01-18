#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int n, maxx, sum;
char a[10][10];
bool g = 0;

void bfs(int x, int y)
{
	io_optimized
	if (a[x][y] == 'B')
	{
		g = 1;
		maxx = max(maxx, sum);
	}
	else
	{
		sum += (a[x][y] - '0');
		if (y < n - 1 && a[x][y + 1] != 'X')
		{
			bfs(x, y + 1);
		}
		if (x < n - 1 && a[x + 1][y] != 'X')
		{
			bfs(x + 1, y);
		}
		sum -= (a[x][y] - '0');
	}
}

int main() {
	io_optimized
	string bs;
	while (cin >> n)
	{
		maxx = 0;
		g = 0;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> bs;
			for (int j = 0; j < n; j++)
			{
				a[i][j] = bs[j];
			}
		}
		if (a[0][1] != 'X')
		{
			bfs(0, 1);
		}
		if (a[1][0] != 'X')
		{
			bfs(1, 0);
		}
		if (g)
		{
			cout << maxx << "\n";
		}
		else
		{
			cout << "X" << "\n";
		}
	}

	return 0;
}
