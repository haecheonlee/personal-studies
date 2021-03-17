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

const int MAX_N = 1e2 + 1;

int a[MAX_N];
bool check[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);
	
	memset(check, false, sizeof(check));
	int L = 0;
	for(int i = 1; i <= N; i++) {
		if(L == a[i]) check[i] = 1, L++;
	}

	for(int i = 0; i < L; i++) cout << i << ' ';
	for(int i = 1; i <= N; i++) if(!check[i]) cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	fastio
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
