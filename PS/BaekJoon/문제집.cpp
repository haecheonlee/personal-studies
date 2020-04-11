#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> list[35000];
int in_degree[35000];

int main() {
	int n,m;
	cin>>n>>m;
	
	int a,b;
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		
		list[a].push_back(b);
		in_degree[b]++;
	}

	// topological sort
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i=1; i<=n; i++) {
		if(in_degree[i]==0) pq.push(i);
	}

	while(!pq.empty()) {
		int current=pq.top();
		pq.pop();
		
		cout<<current<<" ";
		for(int i=0; i<list[current].size(); i++) {
			int next=list[current][i];
			
			in_degree[next]--;
			if(in_degree[next]==0) pq.push(next);
		}
	}

	return 0;
}

/*
INPUT:
4 2
4 2
3 1

OUTPUT:
3 1 4 2
*/
