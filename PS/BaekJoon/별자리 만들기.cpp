#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge {
	int from;
	int to;
	double cost;
	Edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}
	
	bool operator<(const Edge &other) const {
		return cost<other.cost;
	}
};

int p[101];
int Find(int x) {
	if(p[x]==x) return x;
	else return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	p[x]=y;
}

vector<Edge> list;
vector<pair<double,double>> axis;
double d[101][101] {0};

int main() {
	int n;
	cin>>n;

	axis.resize(n+1);
	for(int i=1; i<=n; i++) {
		p[i]=i;
		cin>>axis[i].first>>axis[i].second;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			double dist_x=pow((axis[i].first-axis[j].first),2);
			double dist_y=pow((axis[i].second-axis[j].second),2);
			
			double distance=sqrt(abs(dist_x+dist_y));
			list.push_back(Edge(i,j,distance));
		}
	}

	sort(list.begin(), list.end());
	
	double ans=0;
	for(Edge &e : list) {
		int from=e.from;
		int to=e.to;
		double cost=e.cost;
		
		int x=Find(from);
		int y=Find(to);
		
		if(x!=y) {
			Union(from, to);
			ans+=cost;
		}
	}
	cout<<fixed<<setprecision(2)<<ans;

	return 0;
}

/*
INPUT:
3
1.0 1.0
2.0 2.0
2.0 4.0

OUTPUT:
3.41
*/
