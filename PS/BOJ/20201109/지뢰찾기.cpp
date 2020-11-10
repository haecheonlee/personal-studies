/* reference: https://imnotabear.tistory.com/37 */
#include <iostream>

using namespace std;

const int MAX = 1e2 + 1;

int a[MAX][MAX];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char x;
            cin >> x;
            
            a[i][j] = (x == '#' ? -1 : x - '0');
        }
    }

    int ans = 0;
    if(2 < N) {
        ans = (N - 2) * (N - 2);
        
        for(int i = 1; i < N - 1; i++) {
            for(int j = 1; j < N - 1; j++) {
                if(a[i][j] == -1) {
                    bool mine = true;
                    
                    for(int k = 0; k < 8; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if(0 <= nx && nx < N && 0 <= ny && ny < N) {
                            if(a[nx][ny] == 0) {
                                mine = false;
                                ans -= 1;
                                break;
                            }
                        }
                    }
                    
                    if(mine) {
                        for(int k = 0; k < 8; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            
                            if(0 <= nx && nx < N && 0 <= ny && ny < N) {
                                if(1 <= a[nx][ny] && a[nx][ny] <= 3) a[nx][ny]--;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}
