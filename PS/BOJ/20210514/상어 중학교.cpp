#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second
#define sz(x) (int)x.size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX_N = 30;
const int MAX_M = 10;

// (1 ~ 5): normal block, -1: black block, 0: rainbow block

ll ans = 0;
int N, M;
int a[MAX_N][MAX_N];
bool check[MAX_N][MAX_N], grouped[MAX_N][MAX_N];
vector<pair<vector<pii>, int>> G;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void rotate() {
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N - i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = temp;
        }
    }
}

void fall() {
    // gravity
    for(int j = 0; j < N; j++) {
        for(int i = N - 1; i >= 0; i--) {
            if(a[i][j] == -1) continue;
            int k = i;
            while(k + 1 < N && a[k + 1][j] == -2) {
                swap(a[k][j], a[k + 1][j]);
                k++;
            }
        }
    }
}

void bfs(int sx, int sy) {
    memset(check, false, sizeof(check));

    pair<vector<pii>, int> block;
    vector<pii> g;

    int color = a[sx][sy];
    queue<pii> q;
    q.push({sx, sy});
    check[sx][sy] = 1;

    while(!q.empty()) {
        int x = q.front().fi;
        int y = q.front().sc;
        q.pop();

        grouped[x][y] = 1;
        g.push_back({x, y});

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0 <= nx && nx < N && 0 <= ny && ny < N) {
                if(a[nx][ny] == -1 || check[nx][ny] == true) continue;
                if(a[nx][ny] == 0 || a[nx][ny] == color) {
                    // 0 or same color
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    // making a new group of block
    block.fi = g;
    block.sc = color;

    G.push_back(block);
}

bool go() {
    // search group 
    memset(grouped, false, sizeof(grouped));
    G.clear();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(grouped[i][j] == false && a[i][j] > 0) 
                bfs(i, j);

    int idx = -1, cnt = -1, rainbow = -1, px = -1, py = -1; 
    for(int i = 0; i < sz(G); i++) {
        // must be more than 2 blocks in a group
        if(sz(G[i].fi) <= 1) continue;

        int cntBlock = sz(G[i].fi), cntRainbow = 0, bx = N + 1, by = N + 1;
        for(auto& g : G[i].fi) {
            int x = g.fi, y = g.sc;

            if(a[x][y] == 0) {
                cntRainbow++;
            }else {
                // must be the least position (standard block)
                if(x < bx || (x == bx && y < by)) bx = x, by = y;
            }
        }

        // more rainbow or if equal, largest position 
        bool flag = 0;
        if(cntBlock > cnt) {
        	// check size
			flag = 1;
        } else if(cntBlock == cnt) {
        	if(cntRainbow > rainbow) {
        		// check rainbow
        		flag = 1;
        	} else if(cntRainbow == rainbow) {
        		if(bx > px) {
        			// check row
        			flag = 1;	
        		} else if(bx == px) {
        			// check column
        			if(by > py) flag = 1;
        		}
        	}
        }
        
        if(flag) idx = i, cnt = cntBlock, rainbow = cntRainbow, px = bx, py = by;
    }

    // no group found in the map
    if(idx == -1) return false;

    // add to the ans
    ans += (sz(G[idx].fi) * sz(G[idx].fi));

    // remove from the map
    for(auto& g : G[idx].fi) a[g.fi][g.sc] = -2;

    // gravity
    fall();

    // counter-clockwise
    rotate();

    // gravity
    fall();
    
    return true;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) 
            cin >> a[i][j];

    while(1) if(go() == false) break;   
    cout << ans << '\n';

    return 0;
}
