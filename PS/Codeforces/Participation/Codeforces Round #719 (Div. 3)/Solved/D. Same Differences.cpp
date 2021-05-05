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

ll a[MAX_N];
map<ll,ll> mp;

void solve() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    mp.clear();
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += mp[i - a[i]];
        mp[i - a[i]]++;
    }
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
