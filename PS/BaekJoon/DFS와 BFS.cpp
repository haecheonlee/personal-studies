#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int nodes[1001][1001];
bool check_dfs[1001];
bool check_bfs[1001];
vector<int> vec[1001];

/* adjacency-matrix */
void dfs(int start, int lastIndex) {
	cout<<start<<" ";
	check_dfs[start]=true;
	for(int i=1; i<=lastIndex; i++) {
		if(nodes[start][i] == 1 && check_dfs[i] == false) {
			dfs(i, lastIndex);
		}
	}
}

/* adjacency-list */
void dfs(int start) {
	cout<<start<<" ";
	check_dfs[start]=true;
	for(int i=0; i<vec[start].size(); i++) {
		int y=vec[start][i];
		if(check_dfs[y] == false) {
			dfs(y);
		}
	}
}

/* adjacency matrix */
void bfs(int start, int lastIndex) {
	queue<int> q;
	check_bfs[start]=true; q.push(start);
	while(!q.empty()) {
		cout<<q.front()<<" ";
		int x=q.front(); q.pop();
		for(int i=1; i<=lastIndex; i++) {
			if(nodes[x][i]==1 && check_bfs[i]==false) {
				check_bfs[i]=true;
				q.push(i);
			}
		}
	}
}

/* adjacency list */
void bfs(int start) {
	queue<int> q;
	check_bfs[start]=true; q.push(start);
	while(!q.empty()) {
		cout<<q.front()<<" ";
		int x=q.front(); q.pop();
		for(int i=0; i<vec[x].size(); i++) {
			int y=vec[x][i];
			if(check_bfs[y]==false) {
				check_bfs[y]=true; 
				q.push(y);
			}
		}
	}
}

int main() {
	int n,m,v;
	cin>>n>>m>>v;

	int a,b;
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		
		nodes[a][b]=1;
		nodes[b][a]=1;
		vec[a].push_back(b);
		vec[b].push_back(a);

		sort(vec[a].begin(), vec[a].end());
		sort(vec[b].begin(), vec[b].end());
	}
	
	//dfs(v,n);
	dfs(v);
	cout<<'\n';
	//bfs(v,n);
	bfs(v);
	
	return 0;
}

/*
boj.kr/1260

INPUT:
5 5 3
5 4
5 2
1 2
3 4
3 1

OUTPUT:
3 1 2 5 4
3 1 4 2 5
*/
