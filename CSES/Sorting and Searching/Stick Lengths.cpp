#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n;
	while (cin >> n)
	{
		long long int a[n];
		long long int summ = 0;
		for (auto &i : a)
		{
			cin >> i;
			summ += i;
		}
		long long int ans1 = 0, ans2 = 0;
		sort(a, a + n);
		for (auto &i : a)
		{
			ans1 += abs(i - a[n / 2]);
			ans2 += (summ / n);
		}
		cout << min(ans1, ans2);
	}

	return 0;
}