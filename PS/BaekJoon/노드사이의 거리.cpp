#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int N,M;
vector<int> a[1001];
int d[1001][1001];

int bfs(int start, int end) {
	bool check[N+1] {false};
	
	queue<pi> q;
	q.push(make_pair(start,0));
	check[start]=true;
	
	while(!q.empty()) {
		int x=q.front().first;
		int z=q.front().second;
		q.pop();
		
		if(x==end) return z;
		for(auto& y : a[x]) {
			if(check[y]==false) {
				check[y]=true;
				q.push(make_pair(y,z+d[x][y]));
			}
		}
	}
	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	
	memset(d,-1,sizeof(d));

	for(int i=0; i<N-1; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		
		a[x].push_back(y);
		a[y].push_back(x);
		d[x][y]=d[y][x]=z;
	}
	
	for(int i=1; i<=N; i++) {
		d[i][i]=0;
		bfs(i,i);
	}
	
	while(M--) {
		int a,b;
		cin>>a>>b;
		
		cout<<bfs(a,b)<<'\n';
	}

	return 0;
}
