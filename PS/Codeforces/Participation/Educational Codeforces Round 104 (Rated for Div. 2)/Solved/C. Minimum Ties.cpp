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

const int MAX_N = 110;

int a[MAX_N][MAX_N];

void solve() {
	int N; cin >> N;

	if(N == 2) {
		cout << 0 << '\n';
	} else {
		if(N & 1) {
			for(int i = 1; i <= N; i++) {
				int x = 1;
				for(int j = i + 1; j <= N; j++) {
					a[i][j] = x, a[j][i] = -x;
					x = -x;					
				}
			}
		} else {
			for(int i = 1; i <= N; i++) {
				int x = (i == 1 ? 1 : -a[i - 1][i + 1]);			
				for(int j = i + 1; j <= N; j++) {
					if((i & 1) && (j == i + 1)) {
						a[i][j] = a[j][i] = 0;
					} else {
						a[i][j] = x, a[j][i] = -x;
						x = -x;
					}
				}
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = i + 1; j <= N; j++) cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	fastio

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
