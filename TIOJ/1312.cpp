#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define eb emplace_back
#define F first
#define S second
#define mkp make_pair

int f[10005];

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		f[i] = i;
	}
}

int find(int x)
{
	return (x == f[x] ? x : f[x] = find(f[x]));
}

void unite(int x, int y)
{
	f[find(x)] = find(y);
}

int main() {
	_
	int n, m, x, y, k;
	while (cin >> n >> m)
	{
		init(n);
		while (m--)
		{
			cin >> x >> y;
			unite(x, y);
		}
		cin >> k;
		k = find(k);
		int ans = 1e9;
		for (int i = 1; i <= n; i++)
		{
			if (find(i) == k)
			{
				ans = min(ans, i);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}