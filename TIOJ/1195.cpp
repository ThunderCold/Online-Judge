#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main () {
	io_optimized
	int n;
	string s;
	while (cin >> n)
	{
		int sum = 0;
		while (n--)
		{
			cin >> s;
			if (s[2] == s[3] && s[4] == s[5] && s[3] != s[4])
			{
				sum += 1500;
			}
			else if (s[2] != s[3] || s[4] != s[5])
			{
				sum += 1000;
			}
			else
			{
				sum += 2000;
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
