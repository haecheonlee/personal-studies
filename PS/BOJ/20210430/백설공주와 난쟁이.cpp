#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 3e5 + 10;

int sqrtN = 2000;

struct Query {
	int idx, l, r;
	bool operator < (const Query& x) {
		if(l / sqrtN != x.l / sqrtN) return l / sqrtN < x.l / sqrtN;
		return r < x.r;
	}
};

int res, color;
int a[MAX_N], ans[MAX_N], cnt[MAX_N];
vector<Query> query;

void add(int x) {
	cnt[x]++;
}

void sub(int x) {
	cnt[x]--;
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];

	int Q; cin >> Q;
	for(int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		query.push_back({i, l, r});
	}
	sort(query.begin(), query.end());
	
	memset(ans, -1, sizeof(ans));
	int l = 0, r = 0;
	for(int i = 0; i < Q; i++) {
		while(l < query[i].l) sub(a[l++]);
		while(l > query[i].l) add(a[--l]);
		while(r < query[i].r) add(a[++r]);
		while(r > query[i].r) sub(a[r--]);

		int K = r - l + 1;
		for(int c = 1; c <= M; c++) {
			if(cnt[c] * 2 > K) {
				ans[query[i].idx] = c;
				break;
			}
		}
	}
	
	for(int i = 0; i < Q; i++) {
		if(ans[i] != -1) cout << "yes" << ' ' << ans[i] << '\n';
		else cout << "no" << '\n';
	}
	
	return 0;
}
