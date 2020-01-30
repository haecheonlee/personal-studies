#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,a,b;
int dist[101];
bool check[101];
vector<int> vec[101];

void reset() {
	for(int i=1; i<=n; i++) { 
		dist[i]=0;
		check[i]=false;
	}
}

int bfs(int x){ 
	queue<int> q;
	q.push(x);
	dist[x]=0;
	check[x]=true;
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		for(int i=0; i<vec[now].size(); i++) {
			int next=vec[now][i];
			if(check[next]==false) {
				check[next]=true;
				dist[next]=dist[now]+1;
				q.push(next);
			}
		}
	}
	
	int total=0;
	for(int i=1; i<=n; i++) {
		total+=dist[i];
	}
	
	return total;
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	int idx=0, min_value=5001;
	for(int i=1; i<=n; i++) {
		reset();
		
		int result=bfs(i);
		if(min_value>result) {
			min_value=result;
			idx=i;
		}
	}
	
	cout<<idx;
	
	return 0;
}

/*
boj.kr/1389

INPUT:
5 5
1 3
1 4
4 5
4 3
3 2

OUTPUT:
3
*/
