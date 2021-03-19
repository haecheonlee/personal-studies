/* Codeforces */

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
// #define _DEBUG

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
/* ---------------------------------- template ends ---------------------------------- */

const int MAX_N = 1e2 + 1;

pii p[MAX_N];

void solve() {
    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> p[i].fi >> p[i].sc;
    
    for(int i = 0; i < N; i++) {
        bool ans = 1;
        for(int j = 0; j < N && ans; j++) {
            int d = abs(p[i].fi - p[j].fi) + abs(p[i].sc - p[j].sc);
            if(d > K) ans = 0;
        }
        
        if(ans) {
            cout << 1 << '\n';
            return;
        }
    }
    
    cout << -1 << '\n';
}

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    
    fastio
    
    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
