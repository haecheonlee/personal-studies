#include <iostream>
#include <set>

using namespace std;

const int INF = 1e9 + 1;

void solve() {
	int N, K; cin >> N >> K;
	
	set<int> s;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	while(K) {
		int mx = *(s.rbegin()), mn = INF;
		for(auto it = s.begin(); it != s.end(); it++) {
			if(it == s.begin()) {
				if(*it != 0) {
					mn = 0;
					break;
				}
			}
			
			if(next(it, 1) != s.end()) {
				int nxt = *next(it, 1);
				if(nxt - *it != 1) {
					mn = *it + 1;
					break;
				}
			}
		}
		
		if(mn == INF) {
			cout <<	s.size() + K << '\n';
			return;
		} else {
			int sum = mx + mn;
			int nxt = sum / 2 + (sum & 1);
			if(s.find(nxt) != s.end()) {
				break;	
			} else {
				s.insert(nxt);
			}
		}
		
		K--;
	}
	
	cout << s.size() << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
