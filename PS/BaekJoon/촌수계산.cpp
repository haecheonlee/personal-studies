#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[101];
int dist[101];
bool visited[101], chk;
int t1,t2,result;

void dfs(int x, int count) {
	if(t2==x) {
		chk=true;
		result=count;
		return;
	}
	
	visited[x]=true;
	for(int i=0; i<vec[x].size(); i++) {
		int next=vec[x][i];
		
		if(!visited[next]) {
			visited[next]=true;
			dfs(next, count+1);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);

	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		if(current==t2) break;
		for(int i=0; i<vec[current].size(); i++) {
			int next=vec[current][i];
			
			if(!dist[next]) {
				q.push(next);
				dist[next]=dist[current]+1;
			}
		}
	}
}

int main() {
	int n,m,x,y;
	cin>>n>>t1>>t2>>m;

	for(int i=0; i<m; i++) {
		cin>>x>>y;
		
		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	/*
	dfs(t1,0);
	if(chk) cout<<result;
	else cout<<-1;
	*/
	
	bfs(t1);
	if(dist[t2]) cout<<dist[t2];
	else cout<<-1;
	
	return 0;
}

/*
boj.kr/2644

INPUT:
9
7 3
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6

OUTPUT:
3
*/
