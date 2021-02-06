#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 1;

int a[MAX_N];

void solve() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	vector<int> p;
	for(int i = 1; i <= N; i++) {
		if(a[i] & 1) {
			int j = i;
			while(j < N && !(a[j + 1] & 1)) j++;
			p.push_back(j);
			i = j;
		}
	}

	int SZ = p.size();
	if(SZ < K) {
		cout << "NO" << '\n';
	} else if(SZ == K) {
		cout << "YES" << '\n';
		for(int i = 0; i < SZ; i++) cout << p[i] << ' ';
		cout << '\n';
	} else {
		if((SZ - K + 1) % 2 == 0) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			for(int i = SZ - K; i < SZ; i++) cout << p[i] << ' ';
			cout << '\n';
		}
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
