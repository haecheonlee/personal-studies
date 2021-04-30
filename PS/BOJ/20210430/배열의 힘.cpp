#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 10;

int sqrtN = 2000;

struct Query {
	int idx, l, r;
	bool operator < (const Query& x) {
		if(l / sqrtN != x.l / sqrtN) return l / sqrtN < x.l / sqrtN;
		return r < x.r;
	}
};

ll sum = 0;
int a[MAX_N], cnt[MAX_N * 10];
ll ans[MAX_N];
vector<Query> query;

void add(int x) {
	sum -= (1LL * cnt[x] * cnt[x] * x);
	cnt[x]++;
	sum += (1LL * cnt[x] * cnt[x] * x);
}

void sub(int x) {
	sum -= (1LL * cnt[x] * cnt[x] * x);
	cnt[x]--;
	sum += (1LL * cnt[x] * cnt[x] * x);
}

int main() {
	fastio
	
	int N, Q; cin >> N >> Q;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	for(int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		query.push_back({i, l, r});
	}
	sort(query.begin(), query.end());
	
	int l = 0, r = 0;
	for(int i = 0; i < Q; i++) {
		while(l < query[i].l) sub(a[l++]);
		while(l > query[i].l) add(a[--l]);
		while(r > query[i].r) sub(a[r--]);
		while(r < query[i].r) add(a[++r]);
		ans[query[i].idx] = sum;
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << '\n';

	return 0;
}
