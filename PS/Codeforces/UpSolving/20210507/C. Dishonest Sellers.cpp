#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

vector<pii> a;

bool cmp(const pii& l, const pii& r) {
	int ld = l.fi - l.sc, rd = r.fi - r.sc;
	return ld < rd;
}

int main() {
	int N, K; cin >> N >> K;
	a.resize(N);
	for(int i = 0; i < N; i++) cin >> a[i].fi;
	for(int i = 0; i < N; i++) cin >> a[i].sc;
	sort(a.begin(), a.end(), cmp);

	long long ans = 0, cnt = 0;
	for(int i = 0; i < N; i++) {
		ans += a[i].fi;
		if(a[i].fi > a[i].sc) ans += (a[i].sc - a[i].fi);
		if(a[i].fi <= a[i].sc) cnt++;
	}
	
	for(int i = 0; i < N && cnt < K; i++) {
		if(a[i].fi > a[i].sc) {
			ans += (a[i].fi - a[i].sc);
			cnt++;
		}
	}

	cout << ans << '\n';
	
	return 0;
}
