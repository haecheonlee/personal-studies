#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int N; cin >> N;
	int a[N];
	
	vector<int> p;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		if(a[i] == 1 || a[i] == N) p.push_back(i + 1);	
	}
	
	cout << min(p[0] + (N - p[1] + 1), min(p[1], N - p[0] + 1)) << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
