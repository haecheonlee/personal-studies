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

const int INF = 1e9;
const int MAX = 25;

string a, b;
int d[MAX][MAX][MAX][MAX];

int go(int al, int ar, int bl, int br, int cnt) {
    string aa = a.substr(al, (ar - al + 1)), bb = b.substr(bl, (br - bl + 1));
    if(aa == bb) return cnt;
    
    int& ret = d[al][ar][bl][br];
    if(ret != -1) return ret; 
    ret = INF;
    
    if(al < ar) ret = min(ret, min(go(al + 1, ar, bl, br, cnt + 1), go(al, ar - 1, bl, br, cnt + 1)));
    if(bl < br) ret = min(ret, min(go(al, ar, bl + 1, br, cnt + 1), go(al, ar, bl, br - 1, cnt + 1)));
    
    return ret;
}

void solve() {
    cin >> a >> b;
    
    memset(d, -1, sizeof(d));
    int ans = go(0, sz(a) - 1, 0, sz(b) - 1, 0);
    cout << (ans == INF ? sz(a) + sz(b) : ans) << '\n';
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
