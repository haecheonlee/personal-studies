/* editorial */

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int N; cin >> N;
	
	int odd = 0, evenGood = 0, evenBad = 0;
	for(int i = 0; i < N; i++) {
		string s; cin >> s;

		if(s.size() & 1) odd++;
		int zero = 0;
		for(auto& c : s) if(c == '0') zero++;
		
		if(zero & 1) evenBad++;
		else evenGood++;
	}
	cout << N - (odd == 0 && evenBad % 2 == 1 ? 1 : 0) << '\n';
}

int main() {
	int Q; cin >> Q;
	while(Q--) solve();

	return 0;
}
