#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> list[35000];
int in_degree[35000];
int n,m;

int main() {
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) in_degree[i]=0;
	
	int s1,s2;
	for(int i=1; i<=m; i++) {
		cin>>s1>>s2;
	
		list[s1].push_back(s2);
		in_degree[s2]+=1;
	}

	// topological sort
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(in_degree[i]==0) q.push(i);
	}

	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		cout<<current<<" ";
		for(int i=0; i<list[current].size(); i++) {
			int next=list[current][i];
			in_degree[next]-=1;
			if(in_degree[next]==0) q.push(next);
		}
	}

	return 0;
}

/*
INPUT:
