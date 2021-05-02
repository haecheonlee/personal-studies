#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N =  5e5 + 10;

int sqrtN = 2000;

struct Query {
	int idx, l, r;
	bool operator < (const Query& x) {
		if(l / sqrtN != x.l / sqrtN) return l / sqrtN < x.l / sqrtN;
		return r < x.r;
	}
};

int a[MAX_N], ans[MAX_N], cnt[MAX_N], table[MAX_N];
vector<int> b;
vector<Query> query;

void add(int x) {
	if(cnt[x]) table[cnt[x]]--;
	cnt[x]++; table[cnt[x]]++;
}

void sub(int x) {
	if(cnt[x]) table[cnt[x]]--;
	cnt[x]--; table[cnt[x]]++;
}

int main() {
	fastio
	
	int N, Q; cin >> N >> Q;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i = 1; i <= N; i++) 
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		
	for(int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		query.push_back({i, l, r});
	}
	sort(query.begin(), query.end());
	
	int l = query[0].l, r = query[0].r;
	for(int i = l; i <= r; i++) add(a[i]);
	ans[query[0].idx] = table[2];
	
	for(int i = 1; i < Q; i++) {
		while(l > query[i].l) add(a[--l]);
		while(r < query[i].r) add(a[++r]);
		while(l < query[i].l) sub(a[l++]);
		while(r > query[i].r) sub(a[r--]);
		ans[query[i].idx] = table[2];
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << '\n';
	
	return 0;
}
