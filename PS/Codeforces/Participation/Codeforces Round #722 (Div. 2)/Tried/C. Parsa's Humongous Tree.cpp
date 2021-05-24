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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
/* ---------------------------------- template ends ---------------------------------- */

// #define _DEBUG

const int MAX_N = 2e5 + 10;

int N;
int a[MAX_N][2];
vector<int> G[MAX_N];
ll d[MAX_N];

ll bfs(int k) {
    memset(d, -1, sizeof(d));
    
    queue<pii> q;
    q.push({1, a[1][k]});
    d[1] = 0;
    
    ll sum = 0;
    while(!q.empty()) {
        int x = q.front().fi;
        ll c = q.front().sc;
        q.pop();
        
        for(auto& y : G[x]) {
            ll l = abs(a[y][0] - c), r = abs(a[y][1] - c);
            ll nc = d[x];
            
            if(l > r) {
                nc += l;
                if(d[y] == -1) {
                    sum += l;
                    d[y] = nc;
                    q.push({y, a[y][0]});
                }
            } else {
                nc += r;
                if(d[y] == -1) {
                    sum += r;
                    d[y] = nc;
                    q.push({y, a[y][1]});
                }
            }
        }
    }
    
    return sum;
}

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) G[i].clear();
    for(int i = 1; i <= N; i++) cin >> a[i][0] >> a[i][1];
    for(int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll r1 = bfs(0);
    ll r2 = bfs(1);
    cout << max(r1, r2) << '\n';
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
