/* editorial */

#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 1;

int p[MAX_N];

int main() {
	int N, M, Q; cin >> N >> M >> Q;
	string s, t; cin >> s >> t;

	for(int i = 0; i < N - M + 1; i++) {
		bool flag = 1;
		for(int j = 0; j < M; j++) {
			if(s[i +j] != t[j]) flag = 0;
		}
	
		p[i + 1] = p[i] + flag;
	}

	while(Q--) {
		int l, r; cin >> l >> r;
		l--, r -= M - 1;
		
		cout << (r >= l ? p[r] - p[l] : 0) << '\n';
	}	

	return 0;
}
