/* reference: https://justicehui.github.io/ps/2019/06/13/BOJ13548/ */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int sqrtN;
struct Query {
	int idx, l, r;
	bool operator < (Query& x) {
		if(l / sqrtN != x.l / sqrtN) return l / sqrtN < x.l / sqrtN;
		return r < x.r;
	}
};

int res;
vector<Query> query;
int a[MAX_N], ans[MAX_N], cnt[MAX_N], table[MAX_N];

void add(int x) {
	if(cnt[x] != 0) table[cnt[x]]--;
	cnt[x]++; table[cnt[x]]++;
	res = max(res, cnt[x]);
}

void sub(int x) {
	table[cnt[x]]--;
	if(cnt[x] == res && !table[cnt[x]]) res--;
	cnt[x]--;
	table[cnt[x]]++;
}

int main() {
	fastio
	
	int N; cin >> N; sqrtN = sqrt(N);
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int Q; cin >> Q;
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
