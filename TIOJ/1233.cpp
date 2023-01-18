#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

bool a[512][512];
int n, m;

void f(int x, int y)
{
	if (x > 0 && y > 0 && a[x - 1][y - 1]) //1
	{
		a[x - 1][y - 1] = 0;
		f(x - 1, y - 1);
	}
	if (x > 0 && a[x - 1][y]) //2
	{
		a[x - 1][y] = 0;
		f(x - 1, y);
	}
	if (x > 0 && y < m - 1 && a[x - 1][y + 1]) //3
	{
		a[x - 1][y + 1] = 0;
		f(x - 1, y + 1);
	}
	if (y > 0 && a[x][y - 1]) //4
	{
		a[x][y - 1] = 0;
		f(x, y - 1);
	}
	if (y < m - 1 && a[x][y + 1]) //6
	{
		a[x][y + 1] = 0;
		f(x, y + 1);
	}
	if (x < n - 1 && y > 0 && a[x + 1][y - 1]) //7
	{
		a[x + 1][y - 1] = 0;
		f(x + 1, y - 1);
	}
	if (x < n - 1 && a[x + 1][y]) //8
	{
		a[x + 1][y] = 0;
		f(x + 1, y);
	}
	if (x < n - 1 && y < m - 1 && a[x + 1][y + 1]) //9
	{
		a[x + 1][y + 1] = 0;
		f(x + 1, y + 1);
	}
	return;
}

int main () {
	io_optimized
	string s;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			for (int j = 0; j < m; j++)
			{
				a[i][j] = (s[j] == '1' ? 1 : 0);
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j])
				{
					sum++;
					f(i, j);
				}
			}
		}
		if (sum > 18)
		{
			cout << "10\n";
		}
		else if (sum > 16)
		{
			cout << "9\n";
		}
		else if (sum > 14)
		{
			cout << "8\n";
		}
		else if (sum > 12)
		{
			cout << "7\n";
		}
		else if (sum > 10)
		{
			cout << "6\n";
		}
		else if (sum > 6)
		{
			cout << "5\n";
		}
		else if (sum > 4)
		{
			cout << "4\n";
		}
		else if (sum > 2)
		{
			cout << "3\n";
		}
		else if (sum == 2)
		{
			cout << "2\n";
		}
		else if (sum == 1)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}

	return 0;
}
