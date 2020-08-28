#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
using pi=pair<int,int>;

const int MAX=2e2;

vector<pair<int,pi>> p;
vector<int> a[MAX];
bool check[MAX];

int bfs(int start) {
	memset(check,false,sizeof(check));
	
	queue<int> q;
	q.push(start);

	int total=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(check[y]==false) {
				check[y]=true;
				q.push(y);
				total++;
			}
		}
	}
	
	return total;
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		
		p.push_back({z,{x,y}});
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j) continue;
			
			int x=(p[i].second.first-p[j].second.first);
			int y=(p[i].second.second-p[j].second.second);
			int dist=sqrt((x*x) + (y*y));

			if(dist<=p[i].first) a[i].push_back(j);
		}
	}
	
	int ans=0;
	for(int i=0; i<N; i++) ans=max(ans, bfs(i));
	cout<<ans;
	
	return 0;
}
