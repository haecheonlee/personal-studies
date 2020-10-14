#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+5;
const int MAX_TRAVEL_TIME=100;
const int CLEAN_TIME=5;

vector<pi> a[MAX];
int d[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		if(c<=MAX_TRAVEL_TIME) {
			a[u].push_back({v,c});
			a[v].push_back({u,c});
		}
	}
	
	memset(d, 0x3f, sizeof(d));
	priority_queue<tuple<int,int,int>> q;
	q.push({0,MAX_TRAVEL_TIME,0});
	d[0]=0;
	
	while(!q.empty()) {
		int c,l,x;
		tie(c,l,x)=q.top();
		c=-c;	// reverse sign
		q.pop();
		
		if(d[x]<c) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=c+next.second;
			
			if(l>=next.second) {
				if(d[y]>nc) {
					d[y]=nc;
					q.push({-nc, l-next.second, y});
				}
			} else {
				nc+=5;
				if(d[y]>nc) {
					d[y]=nc;
					q.push({-nc, MAX_TRAVEL_TIME-next.second, y});
				}
			}
		}
	}
	
	cout<<d[N+1];
	
	return 0;
}
