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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int L = -1, R = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            L = i;
            break;
        }
    }
    
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '*') {
            R = i;
            break;
        }
    }
    
    if(L == R) {
        cout << 1 << '\n';
    } else {
        s[L] = s[R] = 'x';
        for(int i = L; i <= R; i++) {
            if(s[i] != 'x') continue;
            int far = i;
            for(int j = i + 1; j <= min(i + k, R); j++) if(s[j] == '*' || s[j] == 'x') far = j;
            s[far] = 'x';
            i = max(far - 1, i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans += (s[i] == 'x');
        cout << ans << '\n';
    }
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
