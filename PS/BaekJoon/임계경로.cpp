#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int taken[10001] {0};
int in_degree1[10001] {0};
int in_degree2[10001] {0};
bool visited[10001];

int main() {
	int n,m;
	cin>>n>>m;
	
	vector<pair<int,int>> a[n+1];
	vector<pair<int,int>> b[n+1];
	
	for(int i=0; i<m; i++) {
		int from, to, cost;
		cin>>from>>to>>cost;
		
		// to get sum
		a[from].push_back(make_pair(to, cost));
		in_degree1[to]++;
		
		// for backtracking
		b[to].push_back(make_pair(from, cost));
		in_degree2[from]++;
	}

	int start, end;
	cin>>start>>end;

	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(in_degree1[i]==0) q.push(i);
	}
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		for(auto next : a[current]) {
			int to=next.first;
			int cost=next.second;
			
			taken[to]=max(taken[to], taken[current]+cost);
			in_degree1[to]--;
			
			if(in_degree1[to]==0) q.push(to);
		}
	}
	
	cout<<taken[end]<<'\n';
	
	// backtracking
	int ans=0;
	visited[end]=true;
	
	for(int i=1; i<=n; i++) in_degree1[i]=in_degree2[i];
	for(int i=1; i<=n; i++) {
		if (in_degree1[i]==0) q.push(i);
	}
	
	while(!q.empty()) {
		int from=q.front();
		q.pop();
		
		for(auto next : b[from]) {
			int to=next.first;
			int cost=next.second;
			
			if(visited[from] && taken[from]-taken[to]==cost) {
				visited[to]=true;
				ans+=1;
			}
			
			in_degree1[to]--;
			if(in_degree1[to]==0) q.push(to);
		}
	}
	cout<<ans;
	
	return 0;
}
