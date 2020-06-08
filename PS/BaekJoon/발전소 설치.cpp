#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

const int inf=1e9;
const int MAX=1e3+1;

pair<int,int> p[MAX];
vector<pair<int,double>> a[MAX];
int v[MAX];
double dist[MAX];
double graph[MAX][MAX];
bool visited[MAX];

double distance(long long x1, long long y1, long long x2, long long y2) {
	long long d1=x1-x2;
	long long d2=y1-y2;
	return sqrt(d1*d1+d2*d2);
}

int main() {
	int n,m;
	double k;
	
	cin>>n>>m>>k;
	
	// setting
	for(int i=1; i<=n; i++) dist[i]=inf;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) graph[i][j]=inf;
	}

	// posotion of each point
	for(int i=1; i<=n; i++) {
		int x,y;
		cin>>x>>y;
		
		p[i]=make_pair(x,y);
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) continue;

			int x1=p[i].first;
			int y1=p[i].second;
			
			int x2=p[j].first;
			int y2=p[j].second;
			
			double cost=distance(x1,y1,x2,y2);
			
			// if less than k connect
			if(cost<=k) graph[i][j]=graph[j][i]=cost;
		}
	}
	
	for(int i=0; i<m; i++) {
		int p1, p2;
		cin>>p1>>p2;
	
		graph[p1][p2]=graph[p2][p1]=0;
	}
	
	priority_queue<pair<double,int>> q;
	q.push(make_pair(0,1));
	dist[1]=0;
	
	while(!q.empty()) {
		int from=q.top().second;
		int cost=-q.top().first;
		q.pop();
		
		for(int i=1; i<=n; i++) {
			if(graph[from][i]==inf) continue;
			if(dist[i]>dist[from]+graph[from][i]) {
				dist[i]=dist[from]+graph[from][i];
				q.push(make_pair(-dist[i],i));
			}
		}
	}
	
	cout<<(int)(dist[n]*1000);
	
	return 0;
}
