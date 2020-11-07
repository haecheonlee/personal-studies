/* reference: https://joonas.tistory.com/49 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const ll LINF = 0x3F3F3F3F3F3F3F3F;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--) {
        int K, N, M;
        cin >> K >> N >> M;
        
        int b[K];
        for(int i = 0; i < K; i++) cin >> b[i];
        
        vector<vector<ll>> d(N + 1, vector<ll>(N + 1, LINF));
        for(int i = 0; i < M; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            
            d[u][v] = min(d[u][v], c + 0LL);
            d[v][u] = min(d[v][u], c + 0LL);
        }
        for(int i = 1; i <= N; i++) d[i][i] = 0;
        
        for(int k = 1; k <= N; k++) {
            for(int i = 1; i <= N; i++) {
                if(d[i][k] == LINF) continue;
                for(int j = 1; j <= N; j++) {
                    if(d[k][j] == LINF) continue;
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
                        
        pair<int,ll> ans {-1, LINF};
        for(int j = 1; j <= N; j++) {
            ll sum = 0;
            bool is_good = true;
            
            for(int i = 0; i < K; i++) {
                if(d[b[i]][j] == LINF) { is_good = false; break; }
                sum += (d[b[i]][j] * d[b[i]][j]);
            }
            
            if(is_good && ans.second > sum) {
                ans.first = j;
                ans.second = sum;
            }
        }
        
        cout << ans.first << ' ' << ans.second << '\n';
    }
    
	return 0;
}
