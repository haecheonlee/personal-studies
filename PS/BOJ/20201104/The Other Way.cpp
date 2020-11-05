#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 9;

vector<pli> a[MAX];
ll d[MAX];
int p[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, S, E;
    cin >> N >> M >> S >> E;
    
    for(int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        
        a[u].push_back({c,v});
        a[v].push_back({c,u});
    }
    
    memset(d, 0x3f, sizeof(d));
    priority_queue<pli> q;
    q.push({0,S});
    d[S] = 0;
    p[S] = 1;
    
    while(!q.empty()) {
        ll c = -q.top().first;
        int x = q.top().second;
        q.pop();
        
        if(d[x] < c) continue;
        for(auto& next : a[x]) {
            int y = next.second;
            ll nc = c + next.first;
            
            if(d[y] > nc) {
                p[y] = p[x];
                d[y] = nc;
                q.push({-nc, y});
            } else if(d[y] == nc) {
                p[y] += p[x];
            }
            
            p[y] %= MOD;
        }
    }
    
    cout << p[E];
    
	return 0;
}
