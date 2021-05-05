#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int N; cin >> N;
	string s; cin >> s;
	
	vector<int> p;
	for(int i = 0; i < N; i++) if(s[i] == '*') p.push_back(i);

	if(p.size() == 0) {
		cout << 0 << '\n';
	} else {
		int half = p.size() / 2;
		int M = p[half];
		
		long long ans = 0, k = 0;
		for(int i = M - half; i <= M + half && k < p.size(); i++) 
			ans += abs(p[k++] - i);
		cout << ans << '\n';
	}
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
