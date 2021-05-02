/* reference: https://justicehui.github.io/ps/2019/10/05/BOJ6515/ */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_NQ = 1e5 + 10;
const int MAX_P = 2e5 + 10;

int sqrtN = 2000;

struct Query {
	int idx, l, r;
	bool operator < (const Query& x) {
		if(l / sqrtN != x.l / sqrtN) return l / sqrtN < x.l / sqrtN;
		return r < x.r;
	}
};

int N, Q; 
int res;
int a[MAX_NQ], ans[MAX_NQ], cnt[MAX_P], table[MAX_NQ];
vector<Query> query;

void add(int x) {
	if(cnt[x]) table[cnt[x]]--;
	cnt[x]++; table[cnt[x]]++;
	res = max(res, cnt[x]);
}

void sub(int x) {
	table[cnt[x]]--;
	if(res == cnt[x] && table[cnt[x]] == 0) res--;
	cnt[x]--; table[cnt[x]]++;
}

void init() {
	cin >> N;
	if(!N) exit(0);
	cin >> Q;
	
	res = 0;
	memset(a, 0, sizeof(a));
	memset(ans, 0, sizeof(ans));
	memset(cnt, 0, sizeof(cnt));
	memset(table, 0, sizeof(table));
	query.clear();
}

void solve() {
	init();
	
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		a[i] += 100000;
	}
	
	for(int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		query.push_back({i, l, r});
	}
	sort(query.begin(), query.end());
	
	int l = query[0].l, r = query[0].r;
	for(int i = l; i <= r; i++) add(a[i]);
	ans[query[0].idx] = res;
	
	for(int i = 1; i < Q; i++) {
		while(l > query[i].l) add(a[--l]);
		while(r < query[i].r) add(a[++r]);
		while(l < query[i].l) sub(a[l++]);
		while(r > query[i].r) sub(a[r--]);
		ans[query[i].idx] = res;
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << '\n';
}

int main() {
	fastio
	
	while(1) solve();
	
	return 0;
}
