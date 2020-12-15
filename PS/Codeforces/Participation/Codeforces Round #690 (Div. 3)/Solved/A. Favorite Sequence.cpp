#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		int a[N + 1];
		for(int i = 1; i <= N; i++) cin >> a[i];

		int L = 1, R = N;
		int ans[N + 1];
		for(int i = 1; i <= N; i++) {
			if(i&1) ans[i] = a[L++];
			else ans[i] = a[R--];
		}

		for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}
