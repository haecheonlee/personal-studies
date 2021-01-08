#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
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

	if(N == 1) {
		cout << 9 << '\n';
	} else {
		int current = 9;
		cout << current << current - 1;
		for(int i = 2; i < N; i++) {
			cout << current++;
			if(current == 10) current = 0;			
		}
		cout << '\n';
	}
}

int main() {
	fastio

	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
