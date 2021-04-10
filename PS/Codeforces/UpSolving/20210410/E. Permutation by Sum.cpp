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
    
    int pMax = 0, pMin = 0, K = N;
    for(int i = L; i <= R; i++) pMax += K--, pMin += i - L + 1;
    
    if(pMax >= S && pMin <= S) {
        int sum = 0;
        for(int i = L; i <= R; i++) {
            a[i] = i - L + 1;
            sum += i - L + 1;
        }
        
        for(int i = R; i >= L; i--) {
            if(i < R) {
                // a[L] < a[L + 1];
                while(sum < S && a[i] + 1 < a[i + 1]) {
                    a[i] += 1;
                    sum++;

                    if(sum == S) goto GOOD;
                }
            } else {
                // a[R] to N
                while(sum < S && a[i] + 1 <= N) {
                    a[i] += 1;
                    sum++;

                    if(sum == S) goto GOOD;
                }
            }
        }
        
        GOOD:
        for(int i = 1; i <= N; i++) if(a[i] != -1) check[a[i]] = 1;
        
        vector<int> p;
        for(int i = 1; i <= N; i++) if(!check[i]) p.push_back(i);
        for(int i = 1; i <= N; i++) {
            if(a[i] == -1) {
                cout << p.back() << ' ';
                p.pop_back();
            } else {
                cout << a[i] << ' ';
            }
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
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
