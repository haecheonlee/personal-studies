#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using PI=pair<int,int>;

struct Edge {
	int from,to;
	double cost;
	
	Edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}
	bool operator<(const Edge &other) const {
		return cost<other.cost;
	}
};

vector<Edge> a;
PI pos[1001];
int p[1001];
bool visited[1001];

int Find(int x) {
	if(x==p[x]) return x;
	else return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(p[x]);
	y=Find(p[y]);
	
	p[x]=y;
}

double getDistance(int x1, int y1, int x2, int y2) {
	double d1=x1-x2;
	double d2=y1-y2;
	
	return sqrt(d1*d1+d2*d2);
}

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) cin>>pos[i].first>>pos[i].second;
	
	for(int i=0; i<m; i++) {
		int from, to;
		cin>>from>>to;
		
		a.push_back(Edge(from, to, 0));
		a.push_back(Edge(to, from, 0));
	}
	
	// setting
	for(int i=1; i<=n; i++) p[i]=i;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			
			double d=getDistance(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
			a.push_back(Edge(i,j,d));
		}
	}
	
	sort(a.begin(), a.end());
	
	double ans=0;
	for(int i=0; i<a.size(); i++) {
		int x=Find(a[i].from);
		int y=Find(a[i].to);
		double cost=a[i].cost;
		
		if(x!=y) {
			Union(x,y);
			ans+=cost;
		}
	}
	cout<<fixed<<setprecision(2)<<ans;
	
	return 0;
}
