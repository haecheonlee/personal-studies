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

const int MAX = 2e3 + 10;
const ll INF = 5e18;

int a[MAX][MAX];
vector<pii> p;
ll d[MAX][MAX];
bool check[MAX][MAX];

void solve() {
    int N, M; cin >> N >> M;
    ll W; cin >> W;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> a[i][j];
            if(a[i][j] > 0) {
                check[i][j] = 1;
                p.push_back({i, j});
            }
            
            d[i][j] = INF;
        }
    }
    
    priority_queue<pair<ll, pii>> pq;
    pq.push({0, {1,1}});
    d[1][1] = 0;
    
    while(!pq.empty()) {
        ll c = -pq.top().fi;
        int x = pq.top().sc.fi;
        int y = pq.top().sc.sc;
        pq.pop();
        if(d[x][y] < c) continue;
        
        // 4-direction
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(1 <= nx && nx <= N && 1 <= ny && ny <= M) {
                if(a[nx][ny] == -1) continue;
                
                if(d[nx][ny] > d[x][y] + W) {
                    d[nx][ny] = d[x][y] + W;
                    pq.push({-d[nx][ny], {nx, ny}});
                }
            }
        }

        // if current pos portal
        if(check[x][y]) {
            for(auto& nxt : p) {
                int nx = nxt.fi, ny = nxt.sc;
                ll nc = c + a[x][y] + a[nx][ny];
                if(d[nx][ny] > nc) {
                    d[nx][ny] = nc;
                    pq.push({-nc, {nx, ny}});
                }
            }
        }      
    }
    
    cout << (d[N][M] == INF ? -1 : d[N][M]) << '\n';
}

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    
    fastio

    solve();
    
	return 0;
}
