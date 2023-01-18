#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main () {
	io_optimized
	int t, n;
	while (cin >> t && t)
	{
		int min = 11, max = 0, sum = 0;
		for (int i = 0; i < t; i++)
		{
			cin >> n;
			if (n < min)
			{
				min = n;
			}
			if (n > max)
			{
				max = n;
			}
			sum += n;
		}
		cout << fixed << setprecision(2) << (double)(sum - min - max) / (t - 2) << "\n";
	}

	return 0;
}
