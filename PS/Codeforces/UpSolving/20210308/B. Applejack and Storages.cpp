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

const int MAX_N = 1e5 + 1;

int cnt[MAX_N];

void add(auto& p, int& x) {
    auto it = p.find(cnt[x]);
    if(it != p.end()) p.erase(it);
    
    cnt[x]++;
    p.insert(cnt[x]);
}

void sub(auto& p, int& x) {
    auto it = p.find(cnt[x]);
    p.erase(it);
    
    cnt[x]--;
    p.insert(cnt[x]);
}

int main() {
    fastio
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    multiset<int> p;
    p.insert(0); p.insert(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;        
        add(p, x);
    }

    int Q; cin >> Q;
    while(Q--) {
        char op; int x;
        cin >> op >> x;

        if(op == '+') add(p, x);
        else if(op == '-') sub(p, x);
        
        bool is_good = 0;
        int square = 4, rectangle = 4;
        for(auto it = p.rbegin(); it != p.rend(); it++) {
            int L = *it;
            if(square && L < 4 || rectangle && L < 2) break;

            if(square && L >= 4) square = 0, L -= 4;
            if(rectangle && L >= 2) rectangle -= 2, L -=2;
            if(rectangle && L >= 2) rectangle -= 2, L -=2;

            if(!square && !rectangle) {
                is_good = 1;
                break;
            }
        }
        
        cout << (is_good ? "YES" : "NO") << '\n';
    }
    
	return 0;
}
