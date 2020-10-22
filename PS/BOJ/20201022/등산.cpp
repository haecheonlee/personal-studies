#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX=25;
const int INF=1e9;

char a[MAX][MAX];
int d[MAX][MAX][MAX][MAX];
bool check[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int convert(char x) {
	if(x>='a' && x<='z') return 26 + x - 'a';
	return x - 'A';
}

int main() {
	int N,M,T,D;
	cin>>N>>M>>T>>D;

	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}

	for(int x=0; x<N; x++) {
		for(int y=0; y<M; y++) {
			for(int nx=0; nx<N; nx++) {
				for(int ny=0; ny<M; ny++) {
					if(x==nx && y==ny) d[x][y][nx][ny]=0;
					else d[x][y][nx][ny]=INF;
				}
			}
		}
	}

	for(int x=0; x<N; x++) {
		for(int y=0; y<M; y++) {
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					int now_height=convert(a[x][y]);
					int next_height=convert(a[nx][ny]);
					int diff=abs(now_height - next_height);
					
					if(diff<=T) {
						if(next_height<=now_height) d[x][y][nx][ny]=1;
						else d[x][y][nx][ny]=diff * diff;
					}
				}
			}
		}
	}

	for(int kx=0; kx<N; kx++) {
		for(int ky=0; ky<M; ky++) {
			for(int x=0; x<N; x++) {
				for(int y=0; y<M; y++) {
					if(d[x][y][kx][ky]==INF) continue;
					for(int nx=0; nx<N; nx++) {
						for(int ny=0; ny<M; ny++) {
							if(d[kx][ky][nx][ny]==INF) continue;
							d[x][y][nx][ny]=min(d[x][y][nx][ny], d[x][y][kx][ky] + d[kx][ky][nx][ny]);
						}
					}
				}
			}
		}
	}

	int ans=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			int asc=d[0][0][i][j], dsc=d[i][j][0][0];
			if(asc + dsc <= D) ans=max(ans, convert(a[i][j]));
		}
	}
	cout<<ans;

	return 0;
}
