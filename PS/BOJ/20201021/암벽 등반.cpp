/* reference: https://ksj14.tistory.com/entry/BaekJoon2412-%EC%95%94%EB%B2%BD-%EB%93%B1%EB%B0%98 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=5e5+5;

int N,K;
vector<int> a[MAX];
vector<pii> p;
int d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>K;
	
	p.resize(N);
	for(int i=0; i<N; i++) cin>>p[i].first>>p[i].second;
	p.push_back({0,0});
	sort(p.begin(), p.end());
	
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(0);
	d[0]=0;
	
	int ans=-1;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		if(p[x].second>=K) {
			ans=d[x];
			break;
		}
		
		for(int y=x-1; y>=0; y--) {
			int nx=abs(p[x].first-p[y].first);
			int ny=abs(p[x].second-p[y].second);
			
			if(nx>2) break;
			if(ny<=2 && d[y]==-1) {
				d[y]=d[x]+1;
				q.push(y);
			}
		}
		
		for(int y=x+1; y<=N; y++) {
			int nx=abs(p[x].first-p[y].first);
			int ny=abs(p[x].second-p[y].second);
			
			if(nx>2) break;
			if(ny<=2 && d[y]==-1) {
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	
	cout<<ans;

	return 0;
}
