#include <iostream>
#include <queue>

using namespace std;

int d[101][101];
char a[101][101];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	int n,m;
	cin>>m>>n;
	
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
			cin>>a[i][j];
            d[i][j] = -1;
        }
    }
	
	queue<pair<int,int>> q;
	queue<pair<int,int>> next_queue;
	q.push(make_pair(0,0));
	d[0][0]=0;
	
	while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (d[nx][ny] == -1) {
                    if (a[nx][ny] == '0') {
                        d[nx][ny] = d[x][y];
                        q.push(make_pair(nx,ny));
                    } else {
                        d[nx][ny] = d[x][y]+1;
                        next_queue.push(make_pair(nx,ny));
                    }
                }
            }
        }
        if (q.empty()) {
            q = next_queue;
            next_queue = queue<pair<int,int>>();
        }
	}
	
	cout<<d[n-1][m-1];
	return 0;
}

/*
boj.kr/1261

INPUT:
6 6
001111
010000
001111
110001
011010
100010

OUTPUT:
2
*/
