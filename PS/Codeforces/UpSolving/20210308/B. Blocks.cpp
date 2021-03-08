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

void solve() {

}

int N;
string s;

void invert(char& x) {
    x = (x == 'B' ? 'W' : 'B');
}

void print(auto& ans) {
    cout << sz(ans) << '\n';
    for(auto& x : ans) cout << x << ' ';
}

int main() {
    fastio
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> N;
    cin >> s;
    
    vector<int> ans;
    // color to white
    for(int i = 0; i < N - 1; i++) {
        if(s[i] == 'B') {
            invert(s[i]); invert(s[i + 1]);
            ans.push_back(i + 1);
        }
    }
    
    if(s.back() == 'B') {
        for(int i = 0; i < N - 1; i++) {
            if(s[i] == 'W') {
                invert(s[i]); invert(s[i + 1]);
                ans.push_back(i + 1);
            }
        }
        
        if(s.back() == 'W') cout << -1 << '\n';
        else print(ans);
    } else {
        print(ans);
    }
    
	return 0;
}
