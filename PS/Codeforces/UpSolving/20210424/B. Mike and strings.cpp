#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 51;

string s[MAX_N];
map<string, int> mp;

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> s[i];

	bool flag = 1;
	for(int i = 0; i < N; i++) {
		int L = s[i].size();
		map<string, bool> check;
		check[s[i]] = 1;
		mp[s[i]] += 0;
		bool found = (i == 0 ? 1 : s[i - 1] == s[i]);
		for(int j = 1; j <= L - 1; j++) {
			string ss = s[i].substr(j, L) + s[i].substr(0, j);
			if(i > 0 && ss == s[i - 1]) found = 1;
			if(ss != s[i] && !check[ss]) mp[ss] += j, check[ss] = 1;
		}
		flag = flag && found;
	}

	int ans = 1e9;
	for(auto each : mp) ans = min(ans, each.second); 
	cout << (flag ? ans : -1) << '\n';

	return 0;
}
