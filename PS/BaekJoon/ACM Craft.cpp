#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int in_degree[1001];
int work[1001];
int measure[1001];

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		vector<int> list[n+1];
		
		for(int i=1; i<=n; i++) { 
			cin>>work[i];
			measure[i]=work[i];
			
			in_degree[i]=0;	
		}
		
		for(int i=0; i<m; i++) {
			int x,y;
			cin>>x>>y;
			
			list[x].push_back(y);
			in_degree[y]+=1;
		}
		
		int target;
		cin>>target;
		
		queue<int> q;
		for(int i=1; i<=n; i++) {
			if(in_degree[i]==0) q.push(i);
		}
		
		while(!q.empty()) {
			int current=q.front();
			q.pop();
			
			for(int i=0; i<list[current].size(); i++) {
				int next=list[current][i];
				
				measure[next]=max(work[next]+measure[current], measure[next]);
				in_degree[next]-=1;
				
				if(in_degree[next]==0) q.push(next);
			}
		}
		
		cout<<measure[target]<<'\n';
	}
	
	return 0;
}

/*
INPUT:
2
4 4
10 1 100 10
1 2
1 3
2 4
3 4
4
8 8
10 20 1 5 8 7 1 43
1 2
1 3
2 4
2 5
3 6
5 7
6 7
7 8
7

OUTPUT:
120
39
*/
