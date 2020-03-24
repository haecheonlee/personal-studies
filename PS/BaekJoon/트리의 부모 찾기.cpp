#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[100001];
bool visited[100001];
int parent[100001];

int main() {
	int n,u,v;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		cin>>u>>v;
		
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	
	queue<int> q;
	q.push(1);
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		for(int next : vec[current]) {
			if(!visited[next]) {
				visited[next]=true;
				parent[next]=current;
				q.push(next);
			}
		}
	}
	
	for(int i=2; i<=n; i++) cout<<parent[i]<<'\n';
	
	return 0;
}

/*
INPUT:
7
1 6
6 3
3 5
4 1
2 4
4 7

OUTPUT:
4
6
1
3
1
4
*/
