#include<bits/stdc++.h>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
	_
	int t;
	string s, tmp;
	while (cin >> t)
	{
		getline(cin, s);
		while (t--)
		{
			getline(cin, s);
			vector<string> v;
			vector<pair<string, string>> va[2];
			stringstream ss;
			ss << s;
			while (ss >> tmp)
			{
				v.push_back(tmp);
			}
			int cur = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == "IF")
				{
					continue;
				}
				else if (v[i] == "not")
				{
					va[cur].push_back(make_pair("", v[i + 1]));
					i++;
				}
				else if (v[i] == "THEN")
				{
					cur = 1;
				}
				else if (v[i] == "and")
				{
					va[cur].push_back(make_pair("", "or"));
				}
				else if (v[i] == "or")
				{
					va[cur].push_back(make_pair("", "and"));
				}
				else
				{
					va[cur].push_back(make_pair("not", v[i]));
				}
			}
			cout << "IF ";
			for (int i = 0; i < va[1].size(); i++)
			{
				if (va[1][i].first != "")
				{
					cout << va[1][i].first << " ";
				}
				if (va[1][i].second != "")
				{
					cout << va[1][i].second << " ";
				}
			}
			cout << "THEN ";
			for (int i = 0; i < va[0].size(); i++)
			{
				if (va[0][i].first != "")
				{
					cout << va[0][i].first << " ";
				}
				if (va[0][i].second != "")
				{
					cout << va[0][i].second << " ";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}