#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N];

int main() {
	int N, Q; cin >> N >> Q;
	
	int one = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] == 1) one++;	
	}
	
	while(Q--) {
		int o, x; cin >> o >> x;
		if(o == 1) {
			if(a[x] == 1) one--, a[x] = 0;
			else one++, a[x] = 1;
		} else {
			cout << (one >= x ? 1 : 0) << '\n';
		}
	}

	return 0;
}
