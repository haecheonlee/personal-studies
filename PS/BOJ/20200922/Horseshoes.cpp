#include <iostream>

using namespace std;

const int MAX=5;

int N;
bool check[MAX][MAX];
char a[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans=0;

void go(int x, int y, bool visited[MAX][MAX], int open, int close) {
	if(open<close) return;
	if(open==close) ans=max(ans, open+close);

	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<N && 0<=ny && ny<N) {
			if(visited[nx][ny]==false) {
				if(close==0) {
					visited[nx][ny]=true;
					if(a[nx][ny]=='(') go(nx, ny, visited, open+1, close);
					else go(nx, ny, visited, open, close+1);
					visited[nx][ny]=false;
				} else {
					if(a[nx][ny]==')') {
						visited[nx][ny]=true;
						go(nx, ny, visited, open, close+1);
						visited[nx][ny]=false;
					}
				}
			}
		}
	}
}

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>a[i][j];
	}
	
	if(a[0][0]==')') {
		cout<<0;
	}
	else {
		check[0][0]=true;
		go(0, 0, check, 1, 0);
		cout<<ans;
	}
	
	return 0;
}
