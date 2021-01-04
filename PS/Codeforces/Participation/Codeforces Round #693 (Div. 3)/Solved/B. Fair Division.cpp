#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve() {
	int N;
	cin >> N;

	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	int L = 0, R = 0;
	for(int i = 0; i < N; i++) {
		if(L == R) L += a[i];
		else if(L < R) L += a[i];
		else if(R < L) R += a[i];
	}
	
	int LL = 0, RR = 0;
	for(int i = N - 1; i >= 0; i--) {
		if(LL == RR) LL += a[i];
		else if(LL < RR) LL += a[i];
		else if(RR < LL) RR += a[i];
	}
	
	cout << (L == R || LL == RR ? "YES" : "NO") << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
