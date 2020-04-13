#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> list[1001];
int in_degree[1001]{0};

int main() {
	int n,m,x;
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		cin>>x;
		
		int a[x];
		for(int j=0; j<x; j++) {
			cin>>a[j];
			if(j>0) {
				list[a[j-1]].push_back(a[j]);
				in_degree[a[j]]+=1;
			}
		}
	}

	vector<int> result;
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(in_degree[i]==0) q.push(i);
	}

	while(!q.empty()) {
		int current=q.front();
		result.push_back(current);
		q.pop();
		
		for(int i=0; i<list[current].size(); i++) {
			int next=list[current][i];
			in_degree[next]-=1;
			
			if(in_degree[next]==0) q.push(next);
		}
	}
	
	if(result.size()==n) {
		for(auto &i : result) cout<<i<<'\n';
	} else {
		cout<<0;
	}
	
	return 0;
}

/*
INPUT:
6 3
3 1 4 3
4 6 2 5 4
2 2 3

OUTPUT:
6
2
1
5
4
3
*/
