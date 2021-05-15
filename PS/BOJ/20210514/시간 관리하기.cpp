#include <iostream>
#include <algorithm>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e3 + 10;

int N;
pii a[MAX_N];

bool chk(int now) {
	for(int i = 0; i < N; i++) {
		now += a[i].sc;
		if(now > a[i].fi) return false;
	}

	return true;	
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i].sc >> a[i].fi;
	sort(a, a + N);
	
	int ans = -1;
	int L = 0, R = 1e6;
	while(L <= R) {
		int M = (L + R) / 2;
		if(chk(M)) L = M + 1, ans = M;
		else R = M - 1;
	}
	cout << ans << '\n';
	
	return 0;
}
