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

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    
    vector<int> b;
    int p = 0, px = 1e9;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i] <= 0) b.push_back(a[i]);
        else if(a[i] > 0) p++, px = min(px, a[i]);
    }
    sort(b.begin(), b.end());
    
    int INF = 1e9;
    int min_n = INF;
    for(int i = 1; i < sz(b); i++) {
        int x = abs(b[i] - b[i - 1]);
        min_n = min(min_n, x);
    }
    
    int ans = sz(b);
    if(p && min_n >= px) ans++;
    cout << ans << '\n';
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
