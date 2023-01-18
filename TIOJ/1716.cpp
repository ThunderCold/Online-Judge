#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main () {
	io_optimized
	int t, a, b, c;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> a >> b >> c;
			cout << (sqrt(b * b - 4 * a * c) == int(sqrt(b * b - 4 * a * c)) ? "Yes\n" : "No\n");
		}
	}

	return 0;
}
