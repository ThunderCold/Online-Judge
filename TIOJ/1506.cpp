#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
	io_optimized
	double a1, a2, b1, b2;
	while (cin >> a1 >> a2 >> b1 >> b2)
	{
		double x = 0, y = 0;
		x = (0 - b1 + b2) / (a1 - a2);
		y = a1 * x + b1;
		if (x < 0)
		{
			cout << "-";
		}
		cout << fixed << setprecision(2) << abs(x) << "\n";
		if (y < 0)
		{
			cout << "-";
		}
		cout << fixed << setprecision(2) << abs(y) << "\n";
	}

	return 0;
}
