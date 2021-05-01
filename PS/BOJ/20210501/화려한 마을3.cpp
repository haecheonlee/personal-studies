#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_NQ = 1e5 + 10;
const int MAX_P= 2e5 + 10;

int sqrtN = 2000;

struct Query {
	int idx, l, r;
	bool operator < (const Query& x) {
		if(l / sqrtN != x.l / sqrtN) return l / sqrtN < x.l / sqrtN;
		return r < x.r;
	}
};

int res;
int a[MAX_NQ], ans[MAX_NQ], cnt[MAX_P], table[MAX_NQ];

void add(int x) {
	if(table[cnt[x]] != 0) table[cnt[x]]--;
	cnt[x]++; table[cnt[x]]++;
	res = max(res, cnt[x]);
}

void sub(int x) {
	table[cnt[x]]--;
	if(res == cnt[x] && table[cnt[x]] == 0) res--;
	cnt[x]--; table[cnt[x]]++;
}

int main() {
	fastio
	
	int N, Q; cin >> N >> Q;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		a[i] += 100000;
	}
	
	vector<Query> query;
	for(int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		query.push_back({i, l, r});
	}
	sort(query.begin(), query.end());
	
	int l = 0, r = 0;
	for(int i = 0; i < Q; i++) {
		while(l < query[i].l) sub(a[l++]);
		while(l > query[i].l) add(a[--l]);
		while(r < query[i].r) add(a[++r]);
		while(r > query[i].r) sub(a[r--]);
		ans[query[i].idx] = res;
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << '\n';
	
	return 0;
}
