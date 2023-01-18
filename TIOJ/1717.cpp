#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int n, t, k, tmp;
int call[1001], d[1001], ans[1001];
vector<int> p[1001], bp[1001];

void bfs(int x)
{
	if (call[x] >= bp[x].size())
	{
		int maxx = 0;
		for (int i : bp[x])
		{
			if (ans[i] > maxx)
			{
				maxx = ans[i];
			}
		}
		ans[x] = d[x] + maxx;
		for (int i : p[x])
		{
			call[i]++;
			bfs(i);
		}
	}
}

int main() {
	io_optimized
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			memset(call, 0, sizeof(call));
			memset(ans, 0, sizeof(ans));
			for (int i = 0; i <= n; i++)
			{
				p[i].clear();
				bp[i].clear();
			}
			for (int i = 1; i <= n; i++)
			{
				cin >> d[i] >> k;
				while (k--)
				{
					cin >> tmp;
					p[i].push_back(tmp);
					bp[tmp].push_back(i);
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (bp[i].empty())
				{
					call[i]++;
					ans[i] = d[i];
					bfs(i);
				}
			}
			int maxx = 0;
			for (int i = 1; i <= n; i++)
			{
				if (p[i].empty())
				{
					maxx = max(maxx, ans[i]);
				}
			}
			cout << maxx << "\n";
		}
	}

	return 0;
}