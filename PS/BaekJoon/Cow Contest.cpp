#include <iostream>

using namespace std;

const int INF=1e9;

int graph[101][101];
bool check[101];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(i==j) graph[i][j]=0;
			else graph[i][j]=INF;
		}
	}
	
	for(int i=0; i<M; i++) {
		int x,y;
		cin>>x>>y;
		graph[x][y]=1;
	}
	
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}
	}
	
	for(int i=1; i<=N; i++) check[i]=true;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(graph[i][j]==INF && graph[j][i]==INF) {
				check[i]=false;	
			}
		}
	}
	
	int ans=0;
	for(int i=1; i<=N; i++) {
		if(check[i]) ans++;
	}
	cout<<ans;
	
	return 0;
}
