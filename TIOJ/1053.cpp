#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main () {
	io_optimized
	int a, b;
	while (cin >> a >> b)
	{
		cout << (max(a, b) % min(a, b) == 0 ? "Y\n" : "N\n");
	}

	return 0;
}
