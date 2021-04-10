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

const int MAX_N = 5e2 + 10;

int a[MAX_N];
bool check[MAX_N];

void solve() {
    int N, L, R, S; cin >> N >> L >> R >> S;
    for(int i = 1; i <= N; i++) {
        a[i] = -1;
        check[i] = 0;
    }
    
    if(L == R) {
        if(S > N) {
            cout << -1 << '\n';
            return;
        } else {
            a[L] = S;
            check[S] = 1;
        }
    } else {
        int K = (R - L + 1);
        int sum = 0;
        for(int i = 1; i < K; i++) sum += i;

        if(S - sum < K) {
            cout << -1 << '\n';
            return;
        } else {
            for(int i = L; i < R; i++) {
                check[i - L + 1] = 1;
                a[i] = i - L + 1;
            }
            a[R] = S - sum;
            check[S - sum] = 1;
        }
    }
        
    vector<int> left;
    for(int i = 1; i <= N; i++) if(!check[i]) left.push_back(i);
    for(int i = 1; i <= N; i++) {
        if(a[i] == -1) {
            a[i] = left.back();
            left.pop_back();
        }
    }

    for(int i = 1; i <= N; i++) cout << a[i] << ' ';
    cout << '\n';
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
