#include <iostream>
#include <vector>

using namespace std;

int a[26];

void solve() {
	int N; cin >> N;
	string s, ss; cin >> s >> ss;

	vector<int> p;
	for(int i = 0; i < N; i++) 
		if(s[i] != ss[i]) 
			p.push_back(i);

	if(p.size() == 2) {
		int F = p[0], S = p[1];
		cout << (s[F] == s[S] && ss[F] == ss[S] ? "YES" : "NO") << '\n';
	} else {
		cout << "NO" << '\n';
	}
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
