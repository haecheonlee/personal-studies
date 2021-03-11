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
// #define _DEBUG

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
/* ---------------------------------- template ends ---------------------------------- */

void solve() {}
const int MAX_N = 5e3 + 10;

int a[MAX_N];

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    
    fastio

    int N, K; cin >> N >> K;
    
    vector<pii> a;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    
    int color = 1;
    int ans[N] { 0 };
    for(int i = 0; i < N; i++) {
        ans[a[i].sc] = color++;
        if(color > K) color = 1;
        
        int j = i + 1, cnt = 1;
        while(j < N && a[i].fi == a[j].fi) {
            ans[a[j].sc] = color++;
            if(color > K) color = 1;
            j++, cnt++;
        }
        i = j - 1;
        
        if(cnt > K) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    cout << "YES" << '\n';
    for(int i = 0; i < N; i++) cout << ans[i] << ' ';
    
	return 0;
}
