/* Codeforces */

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

int H, M;
int invalid[] = {3, 4, 6, 7, 9};

int convert(char x) {
    return x - '0';
}

bool check(const int& x, const int& comp) {
    int L = x / 10, R = x % 10;
    for(int i = 0; i < sizeof(invalid) / sizeof(int); i++)
        if(invalid[i] == L || invalid[i] == R) 
            return false;
    
    if(R == 2) R = 5; else if(R == 5) R = 2;
    if(L == 2) L = 5; else if(L == 5) L = 2;
    
    return R * 10 + L < comp;
}

void foward(int& h, int& m) {
    m++;
    
    if(m == M) m = 0, h++;
    if(h == H) h = 0;
}

void print(int& h, int& m) {
        if(h < 10) cout << 0;
        cout << h;
        cout << ":";
        if(m < 10) cout << 0;
        cout << m;
        cout <<'\n';
}

void solve() {
    cin >> H >> M;
    string s; cin >> s;
    
    int h = convert(s[0]) * 10 + convert(s[1]);
    int m = convert(s[3]) * 10 + convert(s[4]);
    
    for(int i = 0; i <= H * M; i++) {
        if(check(h, M) && check(m, H)) {
            print(h, m);
            return;
        }
        foward(h, m);
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
