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

}

const int MAX_N = 2e5 + 1;

int a[MAX_N];
ll p[MAX_N];

int main() {
	fastio
	
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}

	for(int i = 1; i <= N; i++) {
		if((p[N] + 1) / 2 <= p[i]) {
			cout << i << '\n'; 
			break;
		}
	}

	return 0;
}
