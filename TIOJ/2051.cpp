#include <bits/stdc++.h>
#define io_optimized ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
	io_optimized
	string bs;
	while (cin >> bs)
	{
		cout << bs << "\n";
		pair<string, int> p;
		stack<pair<string, int>> st;
		map<string, int> ma;
		for (int i = 0; i < bs.length(); i++)
		{
			if (bs[i] >= 'A' && bs[i] <= 'Z' && bs[i + 1] >= 'a' && bs[i + 1] <= 'z')
			{
				string s;
				s += bs[i];
				s += bs[i + 1];
				i++;
				int n = 0;
				while (bs[i + 1] >= '0' && bs[i + 1] <= '9')
				{
					n *= 10;
					n += (bs[i + 1] - '0');
					i++;
				}
				if (ma.find(s) == ma.end())
				{
					ma[s] = max(1, n);
				}
				else
				{
					ma[s] += max(1, n);
				}
				p = make_pair(s, max(1, n));
				st.push(p);
			}
			else if (bs[i] >= 'A' && bs[i] <= 'Z')
			{
				string s;
				s += bs[i];
				int n = 0;
				while (bs[i + 1] >= '0' && bs[i + 1] <= '9')
				{
					n *= 10;
					n += (bs[i + 1] - '0');
					i++;
				}
				if (ma.find(s) == ma.end())
				{
					ma[s] = max(1, n);
				}
				else
				{
					ma[s] += max(1, n);
				}
				p = make_pair(s, max(1, n));
				st.push(p);
			}
			else if (bs[i] == '(')
			{
				p = make_pair("(", 1);
				st.push(p);
			}
			else if (bs[i] == ')')
			{
				int n = 0;
				while (bs[i + 1] >= '0' && bs[i + 1] <= '9')
				{
					n *= 10;
					n += (bs[i + 1] - '0');
					i++;
				}
				stack<pair<string, int>> bup;
				while (1)
				{
					if (st.top().first == "(")
					{
						st.pop();
						break;
					}
					n = max(1, n);
					ma[st.top().first] += st.top().second * (n - 1);
					p = make_pair(st.top().first, st.top().second * n);
					bup.push(p);
					st.pop();
				}
				while (!bup.empty())
				{
					st.push(bup.top());
					bup.pop();
				}
			}
		}
		for (auto it = ma.begin(); it != ma.end(); it++)
		{
			cout << it->first << ":" << it->second << "\n";
		}
	}

	return 0;
}
