#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define mp make_pair
#define F first
#define S second

int main() {
	int n, m;
	while (cin >> n >> m)
	{
		pair<int, int> begin, end;
		queue<pair<int, int>> q;
		string s[n + 5];
		int dist[n + 5][m + 5];
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			for (int j = 0; j < m; j++)
			{
				dist[i][j] = 0;
				if (s[i][j] == 'A')
				{
					begin = mp(i, j);
				}
				else if (s[i][j] == 'B')
				{
					end = mp(i, j);
				}
			}
		}
		dist[begin.F][begin.S] = 0;
		q.push(begin);
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (cur == end)
			{
				break;
			}
			if (cur.F > 0 && s[cur.F - 1][cur.S] != '#' && dist[cur.F - 1][cur.S] == 0)
			{
				q.push(mp(cur.F - 1, cur.S));
				dist[cur.F - 1][cur.S] = dist[cur.F][cur.S] + 1;
			}
			if (cur.F < n - 1 && s[cur.F + 1][cur.S] != '#' && dist[cur.F + 1][cur.S] == 0)
			{
				q.push(mp(cur.F + 1, cur.S));
				dist[cur.F + 1][cur.S] = dist[cur.F][cur.S] + 1;
			}
			if (cur.S > 0 && s[cur.F][cur.S - 1] != '#' && dist[cur.F][cur.S - 1] == 0)
			{
				q.push(mp(cur.F, cur.S - 1));
				dist[cur.F][cur.S - 1] = dist[cur.F][cur.S] + 1;
			}
			if (cur.S < m - 1 && s[cur.F][cur.S + 1] != '#' && dist[cur.F][cur.S + 1] == 0)
			{
				q.push(mp(cur.F, cur.S + 1));
				dist[cur.F][cur.S + 1] = dist[cur.F][cur.S] + 1;
			}
		}
		if (dist[end.F][end.S] == 0)
		{
			cout << "NO";
		}
		else
		{
			char ans[dist[end.F][end.S]];
			pair<int, int> cur = end;
			for (int i = dist[cur.F][cur.S] - 1; i >= 0; i--)
			{
				if (i == 0)
				{
					if (mp(cur.F - 1, cur.S) == begin)
					{
						ans[i] = 'D';
						cur = mp(cur.F - 1, cur.S);
					}
					else if (mp(cur.F + 1, cur.S) == begin)
					{
						ans[i] = 'U';
						cur = mp(cur.F + 1, cur.S);
					}
					else if (mp(cur.F , cur.S - 1) == begin)
					{
						ans[i] = 'R';
						cur = mp(cur.F , cur.S - 1);
					}
					else
					{
						ans[i] = 'L';
						cur = mp(cur.F , cur.S + 1);
					}
				}
				else
				{
					if (dist[cur.F - 1][cur.S] == dist[cur.F][cur.S] - 1)
					{
						ans[i] = 'D';
						cur = mp(cur.F - 1, cur.S);
					}
					else if (dist[cur.F + 1][cur.S] == dist[cur.F][cur.S] - 1)
					{
						ans[i] = 'U';
						cur = mp(cur.F + 1, cur.S);
					}
					else if (dist[cur.F][cur.S - 1] == dist[cur.F][cur.S] - 1)
					{
						ans[i] = 'R';
						cur = mp(cur.F , cur.S - 1);
					}
					else
					{
						ans[i] = 'L';
						cur = mp(cur.F , cur.S + 1);
					}
				}

			}
			cout << "YES\n" << dist[end.F][end.S] << "\n";
			for (auto i : ans)
			{
				cout << i;
			}
		}
	}

	return 0;
}