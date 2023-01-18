#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n;
	while (cin >> n && n)
	{
		int a[n];
		double ct = 0;
		for (auto &i : a) cin >> i;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (__gcd(a[i], a[j]) == 1)
				{
					ct += 1;
				}
			}
		}
		if (ct == 0)
		{
			cout << "No estimate for this data set.\n";
		}
		else
		{
			double sum = n * (n - 1) / 2;
			double ans = sqrt(6 * sum / ct);
			cout << fixed << setprecision(6) << ans << "\n";
		}
	}

	return 0;
}