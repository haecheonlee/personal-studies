#include <iostream>

using namespace std;

const int NINF=-2e9-1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M,D;
	cin>>N>>M>>D;
	
	int a[N+1][M+1], d[N+1][M+1];
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			cin>>a[i][j];
			d[i][j]=NINF;	
		}
	}
	
	for(int j=1; j<=M; j++) d[1][j]=0;
	for(int x=1; x<N; x++) {
		for(int y=1; y<=M; y++) {
			if(d[x][y]==NINF) continue;
			
			int xL=min(N+1, x+1+D);
			for(int nx=x+1; nx<xL; nx++) {
				int yL=D-(nx-x);

				for(int ny=max(1, y-yL); ny<=min(y+yL, M); ny++) {
					int dist=abs(nx-x)+abs(ny-y);
					if(dist<=D) {
						int sum=d[x][y]+(a[x][y]*a[nx][ny]);
						d[nx][ny]=max(d[nx][ny], sum);
					}
				}
			}
		}
	}
	
	int ans=NINF;
	for(int j=1; j<=M; j++) {
		ans=max(ans, d[N][j]);
	}
	cout<<ans;
	
	return 0;
}
