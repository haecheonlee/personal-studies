/* reference: https://github.com/kks227/BOJ/blob/master/1400/1430.cpp */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+5;

int N,R,D,x,y;
vector<int> a[MAX];
vector<pi> p;
bool check[MAX];

int main() {
	cin>>N>>R>>D>>x>>y;
	
	p.push_back({x,y});
	for(int i=0; i<N; i++) {
		cin>>x>>y;
		p.push_back({x,y});
	}
	
	for(int i=0; i<=N; i++) {
		for(int j=i+1; j<=N; j++) {
			int x=abs(p[i].first-p[j].first);
			int y=abs(p[i].second-p[j].second);
			
			x*=x, y*=y;
			if(x+y<=R*R) {
				// reachable
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
	}
	
	queue<int> q;
	q.push(0);
	check[0]=true;
	
	double factor=1, ans=0;
	while(!q.empty()) {
		int SIZE=q.size();
		
		for(int i=0; i<SIZE; i++) {
			int x=q.front();
			q.pop();
			
			for(auto& y : a[x]) {
				if(check[y]==false) {
					check[y]=true;
					q.push(y);
					if(y>0) ans+=(factor*D);
				}
			}
		}
		
		factor/=2;
	}
	
	cout<<fixed<<setprecision(2)<<ans;

	return 0;
}
