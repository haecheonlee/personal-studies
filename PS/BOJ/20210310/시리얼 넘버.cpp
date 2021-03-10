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

const int MAX_N = 5e2 + 1;
const int MAX_M = 1e5 + 1;

int a[MAX_N];
int d[2][MAX_M];

void solve() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] %= M;
    }
    
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    for(int i = 0; i < N; i++) {
        int now = i % 2;
        int nxt = (i + 1) % 2;
        
        memset(d[nxt], -1, sizeof(d[nxt]));
        for(int j = 0; j < M; j++) {
            if(d[now][j] == -1) continue;
            
            // skip
            if(d[nxt][j] == -1 || d[nxt][j] < d[now][j]) d[nxt][j] = d[now][j];
            
            // take
            int k = (j + a[i]) % M;
            if(d[nxt][k] == -1 || d[nxt][k] < d[now][j] + 1) d[nxt][k] = d[now][j] + 1;
        }
    }
    cout << d[N % 2][0] << '\n';
}

int main() {
    fastio
    // freopen("input.txt", "r", stdin);
    
    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
