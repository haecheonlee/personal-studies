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
    if(N == 2) {
        cout << -1 << '\n';
    } else {
        int a[N][N];
        int now = 1;
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) a[i][j] = now++;
        
        for(int j = 0; j < N; j++) {
            if(j & 1) {
                int saved = a[N - 1][j];
                for(int i = 0; i < N; i++) {
                    int temp = a[i][j];
                    a[i][j] = saved;
                    saved = temp;
                }
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
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
