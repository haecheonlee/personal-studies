#include <iostream>
#include <algorithm>

using namespace std;

int a[1001][1001];
int d[1001][1001][3];	// 0: left, 1: straight, 2: right

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			if(i==0) d[i][j][0]=d[i][j][1]=d[i][j][2]=a[i][j];
			else d[i][j][0]=d[i][j][1]=d[i][j][2]=1e9;
		}
	}
	
	for(int i=0; i<N-1; i++) {
		for(int j=0; j<M; j++) {
			if(j-1>=0) d[i+1][j-1][0]=min(d[i+1][j-1][0], min(d[i][j][1],d[i][j][2])+a[i+1][j-1]);
			d[i+1][j][1]=min(d[i+1][j][1], min(d[i][j][0], d[i][j][2])+a[i+1][j]);
			if(j+1<M) d[i+1][j+1][2]=min(d[i+1][j+1][2], min(d[i][j][0], d[i][j][1])+a[i+1][j+1]);
		}
	}
	
	int ans=1e9;
	for(int j=0; j<M; j++) ans=min({ans, d[N-1][j][0], d[N-1][j][1], d[N-1][j][2]});
	cout<<ans;
	
	return 0;
}
