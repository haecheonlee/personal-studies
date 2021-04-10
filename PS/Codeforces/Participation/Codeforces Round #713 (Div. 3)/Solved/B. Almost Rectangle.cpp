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

const int MAX_N = 4e2 + 10;

char a[MAX_N][MAX_N];

void solve() {
    int N; cin >> N;

    vector<pii> p;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
            if(a[i][j] == '*') p.push_back({i, j});
        }
    }

    a[p[0].fi][p[1].sc] = '*';
    a[p[1].fi][p[0].sc] = '*';
    
    int cnt = 0;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            cnt += (a[i][j] == '*');
    
    if(cnt == 2) {
        if(p[0].fi == p[1].fi) {
            int x = p[0].fi + 1;
            if(x >= N) x = 0;
            a[x][p[0].sc] = a[x][p[1].sc] = '*';
        } else if(p[0].sc == p[1].sc) {
            int y = p[0].sc + 1;
            if(y >= N) y = 0;
            a[p[0].fi][y] = a[p[1].fi][y] = '*';
        }
    }
   
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cout << a[i][j];
        cout << '\n';
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
