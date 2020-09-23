#include <iostream>

using namespace std;

const int MAX=1e2+1;

bool adj[MAX][MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N-1; i++) {
		int u,v;
		cin>>u>>v;
		
		adj[u][v]=true;
	}

	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(adj[i][j]==false) adj[i][j]=(adj[i][k] && adj[k][j]);
			}
		}
	}

	for(int i=1; i<=N; i++) {
		bool is_possible=true;
		
		for(int j=1; j<=N; j++) {
			if(i==j) continue;
			if(adj[j][i]==false) {
				is_possible=false;
				break;
			}
		}
		
		if(is_possible) {
			cout<<i;
			return 0;
		}
	}
	
	cout<<-1;

	return 0;
}
