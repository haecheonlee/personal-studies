#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
using pi=pair<int,int>;

int graph[1001][1001];

double distance(double x1, double y1, double x2, double y2) {
	double d1=x1-x2;
	double d2=y1-y2;
	
	return sqrt((d1*d1)+(d2*d2));
}

int main() {
	int n;
	
	while(cin>>n) {
		if(n==0) break;
		
		vector<pi> p(n);
		for(int i=0; i<n; i++) cin>>p[i].first>>p[i].second;
		
		bool check[n]{false};
		vector<pair<int,double>> a[n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i==j) continue;
				a[i].push_back(make_pair(j, distance(p[i].first, p[i].second, p[j].first, p[j].second)));
			}
		}

		// mst: prim
		priority_queue<pair<double, int>> q;
		for(auto next : a[0]) q.push(make_pair(-next.second, next.first));
		check[0]=true;
		
		double result=0;
		while(!q.empty()) {
			int to=q.top().second;
			double cost=-q.top().first;
			q.pop();
			
			if(check[to]) continue;
			check[to]=true;
			result+=cost;
			
			for(auto next : a[to]) q.push(make_pair(-next.second, next.first));
		}
		
		cout<<fixed<<setprecision(2)<<result<<'\n';
	}
	
	return 0;
}
