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

int a[MAX_N];
int pos[MAX_N];

void solve() {
    int n; cin >> n;
    
    memset(pos, 0, sizeof(pos));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(!pos[a[i]]) pos[a[i]] = i;
    }
    set<int> p;
    for(int i = 1; i <= n; i++) if(!pos[i]) p.insert(i);
    
    set<int> pp = p;
    for(int i = 1; i <= n; i++) {
        if(pos[a[i]] == i) {
            cout << a[i] << ' ';
        } else {
            // find min in the list
            auto it = pp.begin();
            cout << *it << ' ';
            pp.erase(it);
        }
    }
    cout << '\n';

    pp = p;
    for(int i = 1; i <= n; i++) {
        if(pos[a[i]] == i) {
            cout << a[i] << ' ';
        } else {
            // find max in the list
            auto it = pp.lower_bound(a[i]); it--;
            cout << *it << ' ';
            pp.erase(it);
        }
    }
    cout << '\n';
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
