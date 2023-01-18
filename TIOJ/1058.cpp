#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define ll long long int
using namespace std;

int main() {
	_
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int a = 0, b = 0;
		bool x = 1, y = 1;
		vector<int> v1, v2;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] == '.')
			{
				x = 0;
			}
			else if (x)
			{
				a *= 10;
				a += (s1[i] - '0');
			}
			else
			{
				v1.push_back(s1[i] - '0');
			}
		}
		for (int i = 0; i < s2.length(); i++)
		{
			if (s2[i] == '.')
			{
				y = 0;
			}
			else if (y)
			{
				b *= 10;
				b += (s2[i] - '0');
			}
			else
			{
				v2.push_back(s2[i] - '0');
			}
		}
		if (a > b)
		{
			cout << s1 << "\n";
		}
		else if (a < b)
		{
			cout << s2 << "\n";
		}
		else
		{
			for (int i = 0; i < max(v1.size(), v2.size()); i++)
			{
				if (i >= v1.size())
				{
					cout << s2 << "\n";
					break;
				}
				else if (i >= v2.size())
				{
					cout << s1 << "\n";
					break;
				}
				else if (v1[i] > v2[i])
				{
					cout << s1 << "\n";
					break;
				}
				else if (v1[i] < v2[i])
				{
					cout << s2 << "\n";
					break;
				}
			}
		}
	}

	return 0;
}