#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX=1e4+1;

vector<int> a[MAX];
int d[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		int M;
		cin>>M;

		for(int j=0; j<M; j++) {
			int x;
			cin>>x;
			
			a[i].push_back(x);
		}
	}
	
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(1);
	d[1]=1;
	
	int ans=-1;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		if(a[x].empty()) {
			if(ans==-1 || ans>d[x]) ans=d[x];
		} else {
			for(auto& y : a[x]) {
				if(d[y]==-1) {
					d[y]=d[x]+1;
					q.push(y);
				}
			}
		}
	}
	
	bool all_reached=true;
	for(int i=2; i<=N; i++) {
		if(d[i]==-1) all_reached=false;
	}
	
	if(all_reached) cout<<"Y\n"<<ans;
	else cout<<"N\n"<<ans;
	
	return 0;
}
