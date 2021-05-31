/* BOJ */

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

// #define _DEBUG

struct MCMF {
    struct Edge {
        int to, capacity, cost;
        Edge* rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) { }
    };
    
    int N, source, sink;
    vector<vector<Edge*>> G;
    vector<bool> check;
    vector<pii> from;
    vector<int> distance;
    int INF = 1e9;
    
    MCMF(int N, int source, int sink) : N(N), source(source), sink(sink) {
        G.resize(N);
        check.resize(N);
        distance.resize(N);
        from.resize(N, make_pair(-1, -1));
    }
    
    void add_edge(int u, int v, int capacity, int cost) {
        Edge* ori = new Edge(v, capacity, cost);
        Edge* rev = new Edge(u, 0, -cost);
        
        ori->rev = rev;
        rev->rev = ori;
        
        G[u].push_back(ori);
        G[v].push_back(rev);
    }
    
    void add_edge_from_source(int v, int capacity, int cost) {
        add_edge(source, v, capacity, cost);
    }
    
    void add_edge_to_sink(int u, int capacity, int cost) {
        add_edge(u, sink, capacity, cost);
    }
    
    bool spfa(int& total_flow, int& total_cost) {
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(), INF);
        fill(from.begin(), from.end(), make_pair(-1, -1));
        
        queue<int> q;
        q.push(source);
        distance[source] = 0;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            check[x] = 0;
            for(int i = 0; i < sz(G[x]); i++) {
                int y = G[x][i]->to;
                int flow = G[x][i]->capacity;
                int cost = G[x][i]->cost;
                
                if(flow > 0 && distance[y] > distance[x] + cost) {
                    distance[y] = distance[x] + cost;
                    from[y] = make_pair(x, i);
                    if(!check[y]) {
                        check[y] = 1;
                        q.push(y);
                    }
                }
            }
        }
        
        // never reached
        if(distance[sink] == INF) return false;
        
        // edmond-karp
        int x = sink;
        int c = G[from[x].fi][from[x].sc]->capacity;
        
        while(from[x].fi != -1) {
            int nc = G[from[x].fi][from[x].sc]->capacity;
            if(c > nc) c = nc;
            x = from[x].fi;
        }
        
        x = sink;
        while(from[x].fi != -1) {
            Edge* e = G[from[x].fi][from[x].sc];
            e->capacity -= c;
            e->rev->capacity += c;
            x = from[x].fi;
        }
        
        total_flow += c;
        total_cost += (c * distance[sink]);
        
        return true;
    }
    
    pii flow() {
        int total_flow = 0, total_cost = 0;
        while(spfa(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    fastio

    int N, M; cin >> N >> M;
    
    // source: 0, sink: N + M + 1
    // person: 1 ~ N, task: N + 1 ~ N + M
    MCMF mcmf(N + M + 2, 0, N + M + 1);
    for(int i = 1; i <= N; i++) {
        int q; cin >> q;
        while(q--) {
            int task, cost;
            cin >> task >> cost;
            
            mcmf.add_edge(i, task + N, 1, cost);
        }
    }
    
    // source to person
    for(int i = 1; i <= N; i++) 
        mcmf.add_edge_from_source(i, 1, 0);
    
    // task to sink
    for(int i = 1; i <= M; i++)
        mcmf.add_edge_to_sink(i + N, 1, 0);
        
    auto ans = mcmf.flow();
    cout << ans.fi << '\n' << ans.sc << '\n';
    
	return 0;
}
