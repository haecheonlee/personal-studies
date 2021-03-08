/* editorial */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

const int MAX_N = 1e2 + 1;

int t[MAX_N], l[MAX_N], r[MAX_N];

void solve() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> t[i] >> l[i] >> r[i];
    
    bool ans = 1;
    int L = M, R = M, T = 0;
    for(int i = 0; i < N; i++) {
        R += (t[i] - T);
        L -= (t[i] - T);
        
        if(R < l[i] || L > r[i]) {
            ans = 0;
            break;
        }
        
        R = min(R, r[i]);
        L = max(L, l[i]);
        T = t[i];
    }
    
    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    fastio
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
