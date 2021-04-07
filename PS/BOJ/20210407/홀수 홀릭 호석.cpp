#include <iostream>

using namespace std;

int mx = -1, mn = 1e9;

void go(string& s, int cnt) {
	if(s.size() == 1) {
		mx = max(mx, cnt);
		mn = min(mn, cnt);
		return;
	} else if(s.size() == 2) {
		int sum = 0, extra = 0;
		for(auto& x : s) sum += x - '0';
		string ns = to_string(sum);
		for(auto& x : ns) if(x - '0' & 1) extra++;
		go(ns, cnt + extra);
	} else {
		int N = (int)s.size();
		for(int i = 1; i < N; i++) {
			for(int j = i + 1; j < N; j++) {
				string g1 = s.substr(0, i);
				string g2 = s.substr(i, j - i);
				string g3 = s.substr(j, N - j + 1);
				
				int n1 = stoi(g1), n2 = stoi(g2), n3 = stoi(g3);
				int sum = n1 + n2 + n3, extra = 0;
				string ns = to_string(sum);
				for(auto& x : ns) if(x - '0' & 1) extra++;
				go(ns, cnt + extra);
			}
		}
	}
	
}

int main() {
	string s; cin >> s;
	int odd = 0;
	for(int i = 0; i < s.size(); i++) if(s[i] - '0' & 1) odd++;
	go(s, odd);
	cout << mn << ' ' << mx << '\n';

	return 0;
}
