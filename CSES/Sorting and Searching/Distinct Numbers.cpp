#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);

int main() {
	_
	int n, tmp;
	while (cin >> n)
	{
		set<int> se;
		while (n--)
		{
			cin >> tmp;
			se.insert(tmp);
		}
		cout << se.size();
	}

	return 0;
}