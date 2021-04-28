#include <iostream>
#include <algorithm>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

bool cmp(pii& l, pii& r) {
	return (l.fi - l.sc) < (r.fi - r.sc);	
}

const int MAX_N = 1e5 + 10;

pii p[MAX_N];

int main() {
	ll N, M; cin >> N >> M;
	
	ll sum = 0;
	for(int i = 1; i <= N; i++) {
		cin >> p[i].fi >> p[i].sc;
		sum += p[i].fi;
	}
	sort(p + 1, p + 1 + N, cmp);

	if(sum <= M) {
		cout << 0 << '\n';
	} else {
		for(int i = N; i >= 1; i--) {
			sum -= (p[i].fi - p[i].sc);
			if(sum <= M) {
				cout << N - i + 1 << '\n';
				return 0;
			}
		}
		cout << -1 << '\n';
	}

	return 0;
}
