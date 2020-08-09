#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int MAX=2e5+1;

int N,M;
vector<int> a[MAX];
int d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	
	for(int x=1; x<=N; x++) {
		// initialization
		d[x]=-1;
		
		int y;
		while(cin>>y) {
			if(y==0) break;
			a[x].push_back(y);
		}
	}
	
	queue<pi> q;
	
	cin>>M;
	while(M--) {
		int x;
		cin>>x;
		
		d[x]=0;
		q.push(make_pair(x,0));
	}

	while(!q.empty()) {
		int x=q.front().first;
		int cost=q.front().second;
		q.pop();

		for(auto& y : a[x]) {
			if(d[y]!=-1) continue;
			
			// check if y can believe rumor
			int total=a[y].size();
			int cnt=0;
			
			// y's friends
			for(auto& k : a[y]) {
				if(d[k]!=-1 && d[k]<=cost) cnt++;
			}
			
			if(cnt*2>=total) {
				d[y]=cost+1;
				q.push(make_pair(y,cost+1));
			}
		}
	}
	
	// print answer
	for(int i=1; i<=N; i++) cout<<d[i]<<" ";

	return 0;
}
