#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n;
	while (cin >> n)
	{
		int a[n], b[n + 5];
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[a[i]] = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (b[i + 1] < b[i])
			{
				ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}