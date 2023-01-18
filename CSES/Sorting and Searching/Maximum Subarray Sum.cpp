#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n;
	while (cin >> n)
	{
		long long int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long int ans = a[0], cur = a[0];
		for (int i = 1; i < n; i++)
		{
			cur = max(a[i], cur + a[i]);
			ans = max(ans, cur);
		}
		cout << ans;
	}

	return 0;
}