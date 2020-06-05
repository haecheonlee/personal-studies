#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dist[1000001][11];

int main() {
	memset(dist,-1,sizeof(dist));
	
	int s,k;
	cin>>s>>k;
	
	int ans=-1;
	
	dist[s][0]=0;
	
	queue<pair<int,int>> q;
	q.push(make_pair(s,0));
	
	while(!q.empty()) {
		int now=q.front().first;
		int t=q.front().second;
		q.pop();
	
		if(t==k) {
			ans=max(ans,now);
			continue;
		}
	
		string x=to_string(now);
		int n=x.size();
		
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				if(i==0 && x[j]=='0') continue;
				swap(x[i],x[j]);
				
				int y=stoi(x);
				if(dist[y][t+1]==-1) {
					dist[y][t+1]=dist[now][t]+1;
					q.push(make_pair(y,t+1));
				}
				
				swap(x[i],x[j]);
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
