#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[1001];
bool visited[1001];
int n,m;

int dfs(int x) {
	int count=0;
	visited[x]=true;
	
	for(int i=0; i<vec[x].size(); i++) {
		int idx=vec[x][i];
		
		if(!visited[idx]) {
			count++;
			count+=dfs(idx);
		}
	}
	
	return count;
}

int bfs(int x) {
	int count=0;
	
	queue<int> q;
	q.push(x);
	visited[x]=true;
	
	while(!q.empty()) {
		int idx=q.front();
		q.pop();
		
		for(int i=0; i<vec[idx].size(); i++) {
			int current=vec[idx][i];
			if(!visited[current]) {
				visited[current]=true;
				q.push(current);
				count++;
			}
		}
	}
	
	return count;
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		cin>>n>>m;
		
		for(int i=1; i<=n; i++) {
			visited[i]=false;
			vec[i].clear();
		}
		
		int a,b;
		for(int i=0; i<m; i++) {
			cin>>a>>b;
			
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		
		int flights=0;
		
		// flights=dfs(1);
		flights=bfs(1);
		cout<<flights<<'\n';
	}
	return 0;
}

/*
boj.kr/9372

INPUT:
2
3 3
1 2
2 3
1 3
5 4
2 1
2 3
4 3
4 5

OUTPUT:
2
4
*/
