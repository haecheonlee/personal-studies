#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, a, b; cin >> N >> a >> b;
	string s; cin >> s;

	if(a < b) swap(a, b);

	int one = 0;
	vector<int> p;
	for(int i = 0; i < N; i++) {
		if(s[i] == '.') {
			int LEN = 1;
			while(i + 1 < N && s[i + 1] == '.')
				LEN++, i++;
			if(LEN == 1) one++;
			else p.push_back(LEN);
		}
	}

	int ans = 0;
	for(auto& x : p) {
		int L = x / 2;
		int R = x - L;

		if(a > b) {
			L = min(b, L), R = min(a, R);
			a -= R;
			b -= L;
		} else {
			L = min(a, L), R = min(b, R);
			a -= L;
			b -= R;	
		}

		ans += L + R;
	}

	int k = min(a, one);
	a -= k;
	one -= k;
	ans += k;

	k = min(b, one);
	one -= k;
	b -= k;
	ans += k;

	cout << ans << '\n';

	return 0;
}
