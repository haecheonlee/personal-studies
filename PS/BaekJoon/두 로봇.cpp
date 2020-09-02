#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e5+1;

int N, R1, R2;
vector<pi> a[MAX];
int d1[MAX];	// dist from robot1 to all
int d2[MAX];	// dist from robot2 to all
bool check[MAX];

void bfs(int start, int *d) {
	fill(d, d+N+1, -1);

	queue<int> q;
	q.push(start);
	d[start]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& next : a[x]) {
			int y=next.first;
			int cost=next.second;
			
			if(d[y]==-1) {
				d[y]=d[x]+cost;
				q.push(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>R1>>R2;
	
	for(int i=0; i<N-1; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	bfs(R1,d1);
	bfs(R2,d2);

	// bfs for answer
	int ans=(N==1 || R1==R2) ? 0 : -1;

	queue<int> q;
	q.push(R1);
	check[R1]=true;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();

		for(auto& next : a[x]) {
			int y=next.first;
			
			if(check[y]==false) {
				int sum=d1[x]+d2[y];
				if(ans==-1 || ans>sum) ans=sum;
				check[y]=true;
				q.push(y);
			}
		}
	}
	cout<<ans;

	return 0;
}
