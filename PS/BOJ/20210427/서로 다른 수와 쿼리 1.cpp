/* reference: https://justicehui.github.io/ps/2019/09/11/BOJ14897/ */

# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e6 + 10;

int sqrtN = 2000;

struct Query {
	int idx, s, e;
	
	bool operator < (Query &x) {
		if(s / sqrtN != x.s / sqrtN) return s / sqrtN < x.s / sqrtN;
		return e < x.e;
	}
};


int now = 0;
vector<Query> query;
vector<int> a, b, ans;
int p[MAX_N];

void sub(int i) {
	p[a[i]]--;
	if(p[a[i]] == 0) now--;
}

void add(int i) {
	if(p[a[i]] == 0) now++;
	p[a[i]]++;
}

int main() {
	fastio
	
	int N; cin >> N; a.resize(N + 1);
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	b = a;
	sort(b.begin() + 1, b.end());
	b.erase(unique(b.begin() + 1, b.end()), b.end());
	for(int i = 1; i <= N; i++) 
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

	int Q; cin >> Q; query.resize(Q); ans.resize(Q);
	for(int i = 0; i < Q; i++) {
		cin >> query[i].s >> query[i].e;
		query[i].idx = i;
	}
	sort(query.begin(), query.end());
	
	int s = query[0].s;
	int e = query[0].e;
	int idx = query[0].idx;
	for(int i = s; i <= e; i++) add(i);
	ans[idx] = now;
	
	for(int i = 1; i < Q; i++) {
		idx = query[i].idx;
		while(s < query[i].s) sub(s++);
		while(s > query[i].s) add(--s);
		while(e < query[i].e) add(++e);
		while(e > query[i].e) sub(e--);
		ans[idx] = now;
	}
	for(auto& x : ans) cout << x << '\n';
	
	return 0;
}
