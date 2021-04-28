#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int sqrtN = 2000;

struct Query {
	int idx, s, e;
	
	bool operator < (Query &x) {
		if(s / sqrtN != x.s / sqrtN) return s / sqrtN < x.s / sqrtN;
		return e < x.e;
	}
};

int sum = 0;
int a[MAX_N], ans[MAX_N];
int cnt[MAX_N];
vector<int> b;
vector<Query> q;

void add(int x) {
	if(cnt[x] == 0) sum++;
	cnt[x]++;
}

void sub(int x) {
	cnt[x]--;
	if(cnt[x] == 0) sum--;
}

int main() {
	fastio
	
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		b.push_back(a[i]);
	}
	
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i = 1; i <= N; i++) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	
	int Q; cin >> Q; q.resize(Q);
	for(int i = 0; i < Q; i++) {
		cin >> q[i].s >> q[i].e;
		q[i].idx = i;
	}
	sort(q.begin(), q.end());
	
	int l = q[0].s, r = q[0].e;
	for(int i = l; i <= r; i++) add(a[i]);
	ans[q[0].idx] = sum;
	
	for(int i = 1; i < Q; i++) {
		int ll = q[i].s, rr = q[i].e;
		
		while(ll < l) add(a[--l]);
		while(ll > l) sub(a[l++]);
		while(rr < r) sub(a[r--]);
		while(rr > r) add(a[++r]);
		
		ans[q[i].idx] = sum;
	}
	
	for(int i = 0; i < Q; i++) cout << ans[i] << '\n';

	return 0;
}
