#include <iostream>

using namespace std;

const int inf=1e9;

int graph[501][501];
bool check[501];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) graph[i][j]=0;
			else graph[i][j]=inf;
		}
	}
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin>>a>>b;
		
		graph[a][b]=1;
	}

	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}
	}
	
    for(int i=1; i<=n; i++) check[i]=true;
    
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(graph[i][j]==inf && graph[j][i]==inf) {
				check[i]=false;
				break;
			}
		}
	}
	
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(check[i]) cnt++;
	}
	cout<<cnt;

	return 0;
}
