#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p[26];

int main() {
	int N, K; cin >> N >> K;
	string s; cin >> s;

	s = s + "0";

	int cnt = 0;
	for(int i = 0; i < N; i++) {
		 if(s[i] == s[i + 1]) {
			cnt++;
		} else {
			cnt++;
			
			int x = s[i] - 'a';
			p[x].push_back(cnt);
			cnt = 0;
		}
	}
	
	int ans = 0;	
	for(int i = 0; i < 26; i++) {
		sort(p[i].begin(), p[i].end());
		int cnt = 0;
		for(int j = 0; j < p[i].size(); j++) {
			if(p[i][j] >= K) cnt += (p[i][j] / K);
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';

	return 0;
}
