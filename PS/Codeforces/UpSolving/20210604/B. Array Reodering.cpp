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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

#define _DEBUG

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    
    vector<int> b, c;
    for(int i = 0; i < N; i++) {
        if(a[i] % 2 == 0) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    
    long long ans = sz(b) * sz(c);
    for(int i = 0; i < sz(b); i++) for(int j = i + 1; j < sz(b); j++) {
            if(gcd(b[i], b[j]) > 1) ans++;
    }
    
    for(int i = 0; i < sz(c); i++) for(int j = i + 1; j < sz(c); j++) {
            if(gcd(c[i], c[j]) > 1) ans++;
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
