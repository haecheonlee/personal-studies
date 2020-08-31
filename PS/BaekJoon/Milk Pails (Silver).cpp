#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int d[101][101];

int main() {
	int X,Y,K,M;
	cin>>X>>Y>>K>>M;
	
	// always X<=Y
	if(X>Y) swap(X,Y);
	
	memset(d,-1,sizeof(d));
	queue<pi> q;
	q.push(make_pair(0,0));
	d[0][0]=0;

	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		// no more than K
		if(d[x][y]==K) continue;

		// condition 1 - fill either pail completely to the top
		if(d[x][Y]==-1) {
			d[x][Y]=d[x][y]+1;
			q.push({x,Y});
		}
		
		if(d[X][y]==-1) {
			d[X][y]=d[x][y]+1;
			q.push({X,y});
		}
		
		// condition 2 - He can empty either pail
		if(d[x][0]==-1) {
			d[x][0]=d[x][y]+1;
			q.push({x,0});
		}
		
		if(d[0][y]==-1) {
			d[0][y]=d[x][y]+1;
			q.push({0,y});
		}
		
		// condition 3 - pour the contents of one pail into the other
		int nx, ny, milk;
		// Y to x
		milk=min(y, (X-x));
		nx=x+milk;
		ny=y-milk;
		if(d[nx][ny]==-1) {
			d[nx][ny]=d[x][y]+1;
			q.push({nx,ny});
		}
		
		// x to Y
		milk=min(x, (Y-y));
		nx=x-milk;
		ny=y+milk;
		if(d[nx][ny]==-1) {
			d[nx][ny]=d[x][y]+1;
			q.push({nx,ny});
		}
	}
	
	int ans=-1;
	for(int i=0; i<=X; i++) {
		for(int j=0; j<=Y; j++) {
			if(d[i][j]!=-1) {
				int sum=abs(M-(i+j));
				if(ans==-1 || ans>sum) ans=sum;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
