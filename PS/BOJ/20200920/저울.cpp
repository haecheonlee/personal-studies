#include <iostream>

using namespace std;

const int INF=1e9;
const int MAX=1e2+1;

int a[MAX][MAX];
bool check[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(i==j) a[i][j]=0;
			else a[i][j]=INF;
		}
	}
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u][v]=1;
	}
	
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
			}
		}
	}
	
	for(int i=1; i<=N; i++) {
		int ans=0;
		for(int j=1; j<=N; j++) {
			if(i==j) continue;
			if(a[i][j]==INF && a[j][i]==INF) ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
