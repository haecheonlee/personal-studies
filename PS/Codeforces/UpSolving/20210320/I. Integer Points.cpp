#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	long long o1 = 0, e1 = 0;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		
		if(x & 1) o1++;
		else e1++;
	}
	
	int M; cin >> M;
	long long o2 = 0, e2 = 0;
	for(int i = 0; i < M; i++) {
		int x; cin >> x;
		
		if(x & 1) o2++;
		else e2++;
	}
	
	cout << (o1 * o2) + (e1 * e2) << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
