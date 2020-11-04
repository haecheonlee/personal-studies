#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MAX = 1e3 + 1;
const ll INF = 1e16;

vector<pii> a[MAX];
ll d[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,K,S,E;
    cin>>N>>M>>K>>S>>E;
    
    for(int i = 0; i < M; i++) {
        int u,v,c;
        cin>>u>>v>>c;
        
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
    
    // dijktstra
    for(int i = 1; i <= N; i++) fill(d[i], d[i] + N + 1, INF);
    priority_queue<pair<pii,int>> q;
    q.push({{0, 0}, S});
    d[S][0] = 0;
    
    while(!q.empty()) {
        int c = -q.top().first.first;   // cost
        int e = q.top().first.second;   // number of edges
        int x = q.top().second;
        q.pop();
        
        // check if there's less cost for less used edges
        bool is_bad = false;
        for(int i = 0; i < e; i++) {
            if(d[x][i] < c) { is_bad = true; break; }
        }
        if(is_bad) continue;
        
        // shortest path is always less than N edges
        if(e + 1 >= N) continue;
        if(d[x][e] < c) continue;
        for(auto& next : a[x]) {
            int y = next.first;
            int nc = next.second + c;
            
            if(d[y][e + 1] > nc) {
                d[y][e + 1] = nc;
                q.push({{-nc, e + 1}, y});
            }
        }
    }
    
    // no tax
    int ans = -1;
    for(int i = 0; i < N; i++) if(ans == -1 || ans > d[E][i]) ans = d[E][i];
    cout<<ans<<'\n';
    
    
    // paying tax
    int tax = 0;
    while(K--) {
        int x;
        cin>>x;
        
        tax += x;
        ans = -1;
        for(int i = 0; i < N; i++) 
            if(ans == -1 || ans > d[E][i] + i * tax) ans = d[E][i] + i * tax;
            
        cout<<ans<<'\n';
    }
    
	return 0;
}
