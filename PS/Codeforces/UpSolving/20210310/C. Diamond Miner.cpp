#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>

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

void solve() {
    int N; cin >> N;
    vector<ll> X, Y;
    for(int i = 0; i < N * 2; i++) {
        int x, y; cin >> x >> y;
        if(x == 0) Y.push_back(abs(1LL * y));
        else X.push_back(abs(1LL * x));
    }
    sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
    
    double ans = 0;
    int L = 0;
    for(auto& y : Y) {
        double dist = sqrt(((double)(X[L] * X[L])) + ((double)(y * y)));
        ans += dist;
        L++;
    }
    cout << setprecision(15) << fixed << ans << '\n';
}

int main() {
    fastio
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
