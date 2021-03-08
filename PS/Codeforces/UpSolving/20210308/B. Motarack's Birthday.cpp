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

const int MAX_N = 1e5 + 1;
const int INF = 1e9 + 10;

int a[MAX_N];

void solve() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    
    int mn = INF, mx = -INF;
    for(int i = 0; i < N; i++) {
        if(i > 0 && a[i] == -1 && a[i - 1] != -1)
            mn = min(mn, a[i - 1]), mx = max(mx, a[i - 1]);
        if(i < N - 1 && a[i] == -1 && a[i + 1] != -1)
            mn = min(mn, a[i + 1]), mx = max(mx, a[i + 1]);
    }
    
    int ans = 0;
    int k = (mx + mn) / 2;
    for(int i = 0; i < N; i++) {
        if(a[i] == -1) a[i] = k;
        if(i > 0) ans = max(ans, abs(a[i] - a[i - 1]));
    }
    cout << ans << ' ' << k << '\n';
}

int main() {
    fastio
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
