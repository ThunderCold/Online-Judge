#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define eb emplace_back
#define F first
#define S second
#define mkp make_pair

int f[100005];

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		f[i] = i;
	}
}

int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}

void unite(int x, int y)
{
	f[find(x)] = find(y);
}

int main() {
	_
	int n, m, a, b, c;
	while (cin >> n >> m && !(n == 0 && m == 0))
	{
		ll ans = 0, ct = 0;
		vector<pair<int, pair<int, int>>> v;
		init(n);
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			v.eb(mkp(c, mkp(a, b)));
		}
		if (m < n - 1)
		{
			cout << "-1\n";
			continue;
		}
		sort(v.begin(), v.end());
		for (auto i : v)
		{
			if (find(i.S.F) != find(i.S.S))
			{
				ans += i.F;
				ct++;
				unite(i.S.F, i.S.S);
			}
			if (ct >= n - 1) break;
		}
		if (ct != n - 1) ans = -1;
		cout << ans << "\n";
	}

	return 0;
}