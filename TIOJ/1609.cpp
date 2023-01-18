#include<bits/stdc++.h>
#include <cctype>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define ll long long int

int main() {
	_
	int x, n;
	vector<int> v;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v.emplace_back(x);
		}
		sort(v.begin(), v.end());
		for (int i : v)
		{
			cout << i << " ";
		}
	}

	return 0;
}