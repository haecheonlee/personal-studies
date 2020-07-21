#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int N,M,V,X,Y;
int a[101][101];
int d[101][101];		// -1: not visited
bool visited[101][101];
bool isVolcano[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy, int st) {
	queue<pi> q;
	if(d[sx][sy]==-1 || d[sx][sy]>st) {
		q.push(make_pair(sx,sy));
		d[sx][sy]=st;
	}

	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];

			if(1<=nx && nx<=N && 1<=ny && ny<=M) {
				if(d[nx][ny]==-1 || d[nx][ny]>d[x][y]+1) {
					d[nx][ny]=d[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main() {
    cin>>N>>M>>V;
    cin>>X>>Y;

    // altitude of each area
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
        	cin>>a[i][j];
        	d[i][j]=-1;	
        }
    }

    // volcano
    for(int i=0; i<V; i++) {
        int x,y,t;
        cin>>x>>y>>t;
        
        bfs(x,y,t);
        isVolcano[x][y]=true;
    }
	
	
	// move of a user
	queue<pi> q;
	if(d[X][Y]>0) {
		q.push(make_pair(X,Y));
		d[X][Y]=0;
		visited[X][Y]=true;
	}
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(1<=nx && nx<=N && 1<=ny && ny<=M) {
				if(isVolcano[nx][ny]) continue;
				if(d[nx][ny]>d[x][y]+1) {
					d[nx][ny]=d[x][y]+1;
					visited[nx][ny]=true;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	int max_height=0, max_t=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(visited[i][j]==false) continue;
			if(max_height==a[i][j]) {
				max_t=min(max_t, d[i][j]);
			} else if(max_height<a[i][j]) {
				max_height=a[i][j];
				max_t=d[i][j];
			}
		}
	}
	cout<<max_height<<" "<<max_t;
	
    return 0;
}
