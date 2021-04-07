/* BOJ */

/* reference: codeplus/beakjoon */
/* ---------------------------------- template starts ---------------------------------- */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
/* ---------------------------------- template ends ---------------------------------- */

const int MAX_N = 1e6 + 10;

int N, K, Q;
ll a[MAX_N], cnt[MAX_N], p[MAX_N];
set<int> list;

int main() {
    fastio
	cin >> N >> K;
	for(int i = 1; i <= K; i++) {
		cin >> a[i];
		cnt[a[i]]++;
        list.insert(a[i]);
	}

	p[0] = K;
    for(auto& it : list) {
            for(int k = it; k < N; k += it) p[k] += cnt[it];
    }
    for(int i = 1; i < N; i++) p[i] += p[i - 1];
	cin >> Q;
	
	while(Q--) {
		int L, R; cin >> L >> R;
		cout << p[R] - (L > 0 ? p[L - 1] : 0) << '\n';
	}
    
	return 0;
}
