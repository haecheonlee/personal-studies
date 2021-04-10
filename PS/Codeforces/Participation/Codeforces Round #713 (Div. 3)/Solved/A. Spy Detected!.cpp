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

void solve() {
    int N; cin >> N;
    int cnt[110] {0};
    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    for(int i = 0; i < N; i++) {
        if(cnt[a[i]] == 1) {
            cout << i + 1 << '\n';
            break;
        }
    }
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
