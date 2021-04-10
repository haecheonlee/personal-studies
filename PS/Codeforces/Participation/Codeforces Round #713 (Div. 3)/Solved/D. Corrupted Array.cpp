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

#define _DEBUG

const int MAX_N = 2e5 + 100;

void solve() {
        int N; cin >> N;
        
        vector<ll> b;
        for(int i = 0; i < N + 2; i++) {
            int x; cin >> x;
            b.push_back(x);
        }
        sort(b.begin(), b.end());
        
        ll sum = 0;
        for(int i = 0; i < sz(b) - 1; i++) sum += b[i];
            
        for(int i = 0; i < sz(b) - 1; i++) {
            if(sum - b[i] == b.back() || sum - b[i] == b[i]) {
                // answer
                bool flag = 1;
                for(int j = 0; j < sz(b) - 1; j++) {
                    if(flag && b[i] == b[j]) {
                        flag = 0;
                        continue;
                    }
                    cout << b[j] << ' ';
                }
                cout << '\n';
                return;
            }
        }
        cout << -1 << '\n';
}
int main() {
    #ifdef _DEBUG
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    
    fastio
    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
