/* reference: kks227 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;

const int MAX = 2e2 + 1;
const int INF = 1e9;

int d[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,K,Q;
    cin>>N>>M>>K>>Q;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <=N; j++) {
            d[i][j] = (i == j ? 0 : INF);
        }
    }
    
    for(int i = 0; i < M; i++) {
        int u, v, c;
        cin>>u>>v>>c;
        
        d[u][v] = min(d[u][v], c);
    }
    
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) 
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }

    pil ans = {0,0};
    while(Q--) {
        int u, v, temp = INF;
        cin>>u>>v;
        
        for(int k = 1; k <= K; k++) temp = min(temp, d[u][k] + d[k][v]);
        if(temp < INF) ans.first++, ans.second += temp;
    }
    cout<<ans.first<<'\n'<<ans.second;
    
	return 0;
}
