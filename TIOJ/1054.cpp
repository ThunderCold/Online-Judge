#include<bits/stdc++.h>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
	_
	map<string, int> ma1;
	map<int, string> ma2;
	ma1["Sunday"] = 0; ma2[0] = "Sunday";
	ma1["Monday"] = 1; ma2[1] = "Monday";
	ma1["Tuesday"] = 2; ma2[2] = "Tuesday";
	ma1["Wednesday"] = 3; ma2[3] = "Wednesday";
	ma1["Thursday"] = 4; ma2[4] = "Thursday";
	ma1["Friday"] = 5; ma2[5] = "Friday";
	ma1["Saturday"] = 6; ma2[6] = "Saturday";
	string s;
	int n;
	while (cin >> s >> n)
	{
		cout << ma2[(ma1[s] + n) % 7] << "\n";
	}

	return 0;
}