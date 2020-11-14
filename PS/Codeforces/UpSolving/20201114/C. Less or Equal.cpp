#include <iostream>
#include <map>

using namespace std;

map<int,int> a;

int main() {
	int N, K;
	cin >> N >> K;

	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;

		a[x]++;
	}

	if(K == 0) {
		cout << (a.begin()->first == 1 ? -1 : 1) << '\n';
	} else {
		int ans = -1, k = 0;
		for(auto& x : a) {
			k += x.second;
			if(k == K) ans = x.first;
		}
		cout << ans << '\n';
	}

	return 0;
}
