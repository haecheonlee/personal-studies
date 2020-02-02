#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[300001];
vector<int> result;
int dist[300001];
int n,m,k,x,a,b;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start]=0;
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		for(int i=0; i<vec[current].size(); i++) {
			int next=vec[current][i];
			if(dist[next]==0) {
				q.push(next);
				dist[next]+=dist[current]+1;
			}
		}
	}
}

int main() {
	cin>>n>>m>>k>>x;
	
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		
		vec[a].push_back(b);
	}
	
	bfs(x);

	bool check=true;
	for(int i=1; i<=n; i++) {
		if(dist[i]==k) {
			check=false;
			cout<<i<<'\n';
		}
	}

	if(check) cout<<-1;

	return 0;
}

/*
boj.kr/18352

INPUT:
4 4 1 1
1 2
1 3
2 3
2 4

OUTPUT:
2
3
*/
