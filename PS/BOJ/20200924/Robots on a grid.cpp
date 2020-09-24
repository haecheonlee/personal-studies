#include <iostream>
#include <queue>

using namespace std;
using ll=long long;
using pi=pair<int,int>;

const int MAX=1e3;
const ll M=((ll)1<<31)-1;

char a[MAX][MAX];
ll d[MAX][MAX];
bool check[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>a[i][j];
	}
	
	d[0][0]=1;
	for(int x=0; x<N; x++) {
		for(int y=0; y<N; y++) {
			if(d[x][y]==0) continue;
			
			int nx=x+1;
			int ny=y+1;
			
			if(nx<N) {
				if(a[nx][y]=='.') {
					d[nx][y]+=d[x][y];
					d[nx][y]%=M;
				}
			}
			
			if(ny<N) {
				if(a[x][ny]=='.') {
					d[x][ny]+=d[x][y];
					d[x][ny]%=M;
				}
			}
		}
	}
	
	queue<pi> q;
	q.push({0,0});
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<N) {
				if(check[nx][ny]==false && a[nx][ny]=='.') {
					check[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
	
	ll ans=d[N-1][N-1]%M;
	if(check[N-1][N-1]==false) {
		cout<<"INCONCEIVABLE";
	} else {
		if(ans==0) cout<<"THE GAME IS A LIE";
		else cout<<ans;
	}
	
	return 0;
}
