#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int dx[] = {0,1};
int dy[] = {1,0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N, M;
        cin >> N >> M;
        
        int a[N][M];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) cin >> a[i][j];
        }
        
        for(int k = 0; k < 100; k++) {
            int b[N][M];
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) b[i][j] = a[i][j];
            }
            
            for(int x = 0; x < N; x++) {
                for(int y = 0; y < M; y++) {
                    for(int k = 0; k < 2; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                            
                        if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                            if(a[x][y] == 0 || a[x][y] > 0) a[nx][ny] = abs(a[nx][ny]);
                        }
                    }
                }
            }
            
            if(b == a) break;
        }
        
        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) ans += a[i][j];
        }
        cout << ans << '\n';
    }
    
	return 0;
}
