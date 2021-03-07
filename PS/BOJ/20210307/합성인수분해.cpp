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

int main() {
    fastio
    // freopen("input.txt", "r", stdin);
    
    ll N; cin >> N;    
    vector<ll> p;
    for(ll k = 2; k * k <= N; k++) {
        while(N % k == 0) {
            p.push_back(k);
            N /= k;
        }
    }
    if(N != 1) p.push_back(N);
    
    if(sz(p) == 1) {
        cout << -1 << '\n';
    } else {
        vector<ll> ans;
        int L = (sz(p) & 1 ? sz(p) - 1 : sz(p));
        for(int i = 0; i < L; i += 2) ans.push_back(p[i] * p[i + 1]);
        if(sz(p) & 1) ans[sz(ans) - 1] *= p.back();
            
        for(auto& x : ans) cout << x << ' ';     
    }
    
	return 0;
}
