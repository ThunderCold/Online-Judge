#include<bits/stdc++.h>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
	_
	int a, b;
	while (cin >> a >> b)
	{
		if (a > b)
		{
			for (int i = a; i >= b; i--)
			{
				for (int j = 0; j < i; j++)
				{
					cout << "*";
				}
				cout << "\n";
			}
		}
		else
		{
			for (int i = a; i <= b; i++)
			{
				for (int j = 0; j < i; j++)
				{
					cout << "*";
				}
				cout << "\n";
			}
		}
	}

	return 0;
}