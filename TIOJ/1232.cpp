#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
	io_optimized
	int n, r;
	while (cin >> n >> r)
	{
		bool cut = 0;
		int a[n], ans[n + r + 1][r];
		int ct = 0;
		bool k = 1, b = 1;
		for (int i = 0; i < n; i++)
		{
			a[i] = n - i - 1;
		}
		do
		{
			if (k)
			{
				for (int i = 0; i < r; i++)
				{
					ans[ct][i] = a[i];
				}
				ct++;
				k = 0;
			}
			else
			{
				bool re = 1;
				for (int i = 0; i < r; i++)
				{
					if (a[i] != ans[ct - 1][i])
					{
						re = 0;
					}
					ans[ct][i] = a[i];
				}
				if (!re)
				{
					ct++;
				}
			}
			if (ct == n + r)
			{
				cut = 1;
				break;
			}
		} while (prev_permutation(a, a + n));
		if (cut)
		{
			for (int i = 0; i < r; i++)
			{
				if (!(a[i] == 0 && b))
				{
					cout << a[i];
					b = 0;
				}
			}
		}
		else if (r == 1)
		{
			cout << "0";
		}
		else
		{
			b = 1;
			for (int i = 0; i < r; i++)
			{
				if (!(i == 0 && b))
				{
					cout << i;
					b = 0;
				}
			}
		}
		cout << "\n";
	}

	return 0;
}
