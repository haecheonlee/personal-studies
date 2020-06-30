#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using tpl=tuple<double,int,int>;

int main() {
	int N;
	cin>>N;
	
	priority_queue<tpl> pq;
	for(int i=1; i<=N; i++) {
		double x,y;
		cin>>x>>y;
		
		pq.push({x/y,y,i});
	}
		
	vector<int> ans;
	int cost=0;
	for(int i=0; i<3; i++) {
		double x;
		int y,z;
		tie(x,y,z)=pq.top();
		
		ans.push_back(z);
		cost+=y;
		pq.pop();
	}
	cout<<cost<<'\n';
	for(auto x : ans) cout<<x<<'\n';
	
	return 0;
}
