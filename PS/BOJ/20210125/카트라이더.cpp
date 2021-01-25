#include <iostream>
#include <iomanip>
#include <queue>
#include <limits>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ld> pld;

const int MAX_N = 1e4 + 1;

vector<pair<int, pii>> G[MAX_N];
pld d[MAX_N][11];

bool cmp(const pld& L, const pld& R) {
	return (L.fi != R.fi ? L.fi > R.fi : L.sc > R.sc);
}

int main() {
    fastio
    
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int A, B, L, K;
		cin >> A >> B >> L >> K;

		G[A].push_back({B, {L, K}});
		G[B].push_back({A, {L, K}});
	}
	
	for(int i = 1; i <= N; i++) 
		for(int k = 1; k <= 10; k++) 
			d[i][k].fi = numeric_limits<ll>::max(), d[i][k].sc = numeric_limits<ld>::max();
	priority_queue<pair<pld, pii>, vector<pair<pld, pii>>, greater<pair<pld, pii>>> pq;
	pq.push({{0, 0.0f}, {1, 1}});
	d[1][1] = {0, 0.0};
	
	while(!pq.empty()) {
		ll lc = pq.top().fi.fi;
		ld dc = pq.top().fi.sc;
		int x = pq.top().sc.fi;
		int s = pq.top().sc.sc;
		pq.pop();
		
		if(cmp({lc, dc}, d[x][s])) continue;
		for(auto& nxt : G[x]) {
			int y = nxt.fi;
			ll l = 1LL * nxt.sc.fi;
			int k = nxt.sc.sc;
			
            for(int i = -1; i <= 1; i++) {
                if(s + i >= 1 && s + i <= k) {
                    ll nlc = lc + (l / (s + i));
                    ld ndc = dc + ((ld)(l % (s + i)) / (s + i));
                    
                    if(cmp(d[y][s + i], {nlc, ndc})) {
                        d[y][s + i] = {nlc, ndc};
                        pq.push({{nlc, ndc}, {y, s + i}});
                    }
                }
            }
		}
	}
	
	pld ans {-1, 0};
	for(int k = 1; k <= 10; k++) {
		if(ans.fi == -1 || cmp(ans, d[N][k])) {
			ans.fi = d[N][k].fi, ans.sc = d[N][k].sc;
		}	
	}
	cout << fixed << setprecision(9) << ans.fi + ans.sc << '\n';

	return 0;
}
