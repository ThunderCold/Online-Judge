#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second

string forest[10] = {
	"*****************",
	"*...*.......**..*",
	"**..*....*.*.*..*",
	"*......*.**.**.**",
	"*..**...**..**.**",
	"**.....**..*.*..*",
	"*....*..........*",
	"*.....****.*...**",
	"****.*.*........*",
	"*****************"
};
int fire[10][17];
bool vis[10][17];
bool help;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int fx, fy, T, sx, sy, ex, ey, ans;

void Fire()
{
	queue<pii> q;
	q.emplace(mp(fx, fy));
	while (!q.empty())
	{
		pii cur = q.front();
		//cout << "*" << cur.F << " " << cur.S << "\n";
		for (int i = 0; i < 4; i++)
		{
			if (cur.F + X[i] >= 0 && cur.F + X[i] < 10 && cur.S + Y[i] >= 0 && cur.S + Y[i] < 17 && fire[cur.F + X[i]][cur.S + Y[i]] == 0 && !(cur.F + X[i] == ex && cur.S + Y[i] == ey) && forest[cur.F + X[i]][cur.S + Y[i]] == '.')
			{
				//cout << "#" << cur.F + X[i] << " " << cur.S + Y[i] << "\n";
				q.emplace(mp(cur.F + X[i], cur.S + Y[i]));
				fire[cur.F + X[i]][cur.S + Y[i]] = fire[cur.F][cur.S] + 1;
			}
		}
		q.pop();
	}
}

void sol(int x, int y, int t)
{
	//cout << "*" << x << " " << y << " " << t << "\n";
	if (x == ex && y == ey)
	{
		ans = min(ans, t - T);
		help = 0;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if ((x + X[i] == ex && y + Y[i] == ey) || (x + X[i] > 0 && x + X[i] < 10 && y + Y[i] > 0 && y + Y[i] < 17 && forest[x + X[i]][y + Y[i]] == '.' && t + 1 < fire[x + X[i]][y + Y[i]]))
		{
			if (!vis[x + X[i]][y + Y[i]])
			{
				vis[x + X[i]][y + Y[i]] = 1;
				sol(x + X[i], y + Y[i], t + 1);
				vis[x + X[i]][y + Y[i]] = 0;
			}
		}
	}
}

int main() {
	while (cin >> fx >> fy >> T >> sx >> sy >> ex >> ey)
	{
		help = 1;
		ans = 1e9;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (i == fx && j == fy) fire[i][j] = 1;
				else fire[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		Fire();
		/*for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				cout << fire[i][j] << " ";
			}
			cout << "\n";
		}*/
		sol(sx, sy, T);
		/*for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				cout << fire[i][j] << " ";
			}
			cout << "\n";
		}*/
		if (help)
		{
			cout << "Help!\n";
		}
		else
		{
			cout << ans << "\n";
		}
	}

	return 0;
}