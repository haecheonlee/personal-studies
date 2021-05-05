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

vector<ll> p;

void solve() {
    ll N; cin >> N;
    int ans = 0;
    for(int i = 0; i < sz(p); i++) {
        if(p[i] > N) break;
        ans = i + 1;
    }
    cout << ans << '\n';
}

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    
    fastio
    
    for(int i = 1; i <= 9; i++) {
        ll sum = i;
        while(sum <= 1000000000LL) {
            p.push_back(sum);
            sum = sum * 10 + i;
        }
    }
    sort(p.begin(), p.end());

    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
