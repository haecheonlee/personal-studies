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

map<int, int> m;

void solve() {
    int n; cin >> n;
    
    m.clear();
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        m[x]++;
    }
    
    priority_queue<int> pq;
    for(auto& it : m) pq.push(it.second);
    
    int cnt = 0;
    while(sz(pq) > 1) {
        int L = pq.top(); pq.pop();
        int R = pq.top(); pq.pop();
        
        cnt += 2;
        L--, R--;
        
        if(L) pq.push(L);
        if(R) pq.push(R);
    }
    
    cout << n - cnt << '\n';
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
