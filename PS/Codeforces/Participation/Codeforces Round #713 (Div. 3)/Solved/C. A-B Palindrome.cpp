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
    int a, b; cin >> a >> b;
    string s; cin >> s;

    int N = sz(s);
    for(int i = 0; i < N / 2; i++) {
        if(s[i] == '?' && s[N - i - 1] == '?') continue;
        if(s[i] == s[N - i - 1]) continue;
        
        if(s[i] == '?' || s[N - i - 1] == '?') {
            char x = (s[i] != '?' ? s[i] : s[N - i - 1]);
            s[i] = s[N - i - 1] = x;
        } else {
            cout << -1 << '\n';
            return;
        }
    }
    
    int cntA = 0, cntB = 0, cntK = 0;
    for(int i = 0; i < N; i++) {
        if(s[i] == '0') cntA++;
        else if(s[i] == '1') cntB++;
        else cntK++;
    }
    
    if(cntK == 0) {
        if(cntA == a && cntB == b) cout << s << '\n';
        else cout << -1 << '\n';
    } else {
        if(cntA > a || cntB > b) cout << -1 << '\n';
        else {
            int needA = max(0, a - cntA);
            int needB = max(0, b - cntB);
            
            for(int i = 0; i < N; i++) {
                if(s[i] != '?') continue;
                
                if(i == N - i - 1) {
                    if(needA == 1) s[i] = '0', needA--;
                    else if(needB == 1) s[i] = '1', needB--;
                } else {
                    if(needA >= 2) s[i] = s[N - i - 1] = '0', needA -= 2;
                    else if(needB >= 2) s[i] = s[N - i - 1] = '1', needB -=2;
                }
            }
            
            cntA = cntB = 0;
            for(int i = 0; i < N; i++) {
                if(s[i] == '0') cntA++;
                else if(s[i] == '1') cntB++;
            }
            
            cout << (cntA == a && cntB == b ? s : "-1") << '\n';
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
