#include <iostream>
#include <queue>
#define next _next

using namespace std;

const int INF=1e9;

int a[1001][1001];
int next[1001][1001];
int distance[1001];
bool check[1001];

void path(int x, int y) {
	if(next[x][y]==-1) {
		cout<<0<<endl;
		return;
	}
	
	queue<int> q;
	q.push(x);
	
	while(x!=y) {
		x=next[x][y];
		q.push(x);
	}
	
	cout<<q.size()<<" ";
	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<'\n';
}

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) a[i][j]=0;
			else a[i][j]=INF;
			
			next[i][j]=-1;
		}
	}
	
	for(int i=0; i<m; i++) {
		int from, to, cost;
		cin>>from>>to>>cost;
		
		if(a[from][to]>cost) {
			a[from][to]=cost;
			next[from][to]=to;
		}
	}
	
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(a[i][j]>a[i][k]+a[k][j]) {
					a[i][j]=a[i][k]+a[k][j];
					next[i][j]=next[i][k];
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(a[i][j]==INF) cout<<0<<" ";
			else cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) cout<<0<<'\n';
			else if(a[i][j]==INF) cout<<0<<'\n';
			else path(i,j);
		}
	}

	return 0;
}
