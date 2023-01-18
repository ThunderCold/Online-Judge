#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n;
	while (cin >> n)
	{
		int a[n];
		bool f = 0;
		for (auto &i : a) cin >> i;
		sort(a, a + n);
		long long int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + 1 < a[i])
			{
				cout << sum + 1;
				f = 1;
				break;
			}
			else
			{
				sum += a[i];
			}
		}
		if (!f)
		{
			cout << sum + 1;
		}
	}

	return 0;
}