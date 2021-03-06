/* Editorial */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

const int MAX_N = 2e5 + 1;

int a[MAX_N];

void solve() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    
    bool check = 1;
    for(int i = 1; i <= N; i++) {
        if(a[i] != i) check = 0;
    }
    
    if(check) {
        cout << 0 << '\n';
    } else {
        int ans = 1, stage = 0;
        for(int i = 1; i <= N; i++) {
            if(a[i] == i) {
                if(stage) stage = 2;
            } else {
                if(stage == 0) stage++;
                else if(stage == 2) ans = 2;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    fastio
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int T; cin >> T;
    while(T--) solve();
    
	return 0;
}
