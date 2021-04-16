#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> odd, even;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		if(x & 1) odd.push_back(x);
		else even.push_back(x);
	}
	
	for(int i = 0; i < odd.size(); i++) cout << odd[i] << ' ';
	for(int i = 0; i < even.size(); i++) cout << even[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
