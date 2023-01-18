#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pai pair<ll,ll>
#define F first
#define S second
#define MAXN 1000005
#define INF 1e9

int n, m;
ll d[MAXN];
vector<pai> v[MAXN];

inline void dijkstra(int start)
{
	priority_queue<pai, vector<pai>, greater<pai>> pq;
	for (int i = 0; i <= n; i++) d[i] = INF;
	d[start] = 0;
	pq.push({start, 0});

	while (!pq.empty())
	{
		auto u = pq.top();
		pq.pop();
		if (d[u.F] != u.S) continue;

		for (auto i : v[u.F])
		{
			if (d[i.F] >= u.S + i.S)
			{
				d[i.F] = u.S + i.S;
				pq.push({i.F, d[i.F]});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> m)
	{
		ll a, b, c;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			v[a].push_back({b, c});
		}
		ll ans = 0;
		bool ok = 1;
		dijkstra(1);
		for (int i = 2; i <= n; i++)
		{
			if (d[i] == INF)
			{
				ok = 0;
				break;
			}
			else ans += d[i];
		}
		if (ok)
		{
			for (int i = 2; i <= n; i++)
			{
				dijkstra(i);
				if (d[1] == INF)
				{
					ok = 0;
					break;
				}
				else ans += d[1];
			}
		}
		if (ok)
		{
			cout << ans << "\n";
		}
		else cout << "0\n";
	}

	return 0;
}