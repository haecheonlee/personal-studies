#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool friends[51][51] {false};
int count[51];
int dist[51];

int main() {
	int N;
	cin>>N;
	
	string s[N];
	for(int i=0; i<N; i++) {
		cin>>s[i];
		
		for(int j=0; j<s[i].size(); j++) 
			friends[i][j]=(s[i][j]=='Y');
	}

	for(int i=0; i<N; i++) {
		memset(dist,-1,sizeof(dist));
		dist[i]=0;	// start index
		
		queue<int> q;
		for(int j=0; j<N; j++) {
			if(i==j) continue;
			if(friends[i][j]) {
				dist[j]=1;
				q.push(j);
			}
		}
		
		while(!q.empty()) {
			int current=q.front();
			q.pop();
			
			for(int k=0; k<s[current].size(); k++) {
				if(friends[current][k]) {
					if(dist[k]==-1) {
						dist[k]=dist[current]+1;
						q.push(k);
					}
				}
			}
		}
		
		int cnt=0;
		for(int i=0; i<N; i++) {
			if(1<=dist[i] && dist[i]<=2) cnt++;
		}
		count[i]=cnt;
	}

	int ans=0;
	for(int i=0; i<N; i++) ans=max(ans,count[i]);
	cout<<ans;

	return 0;
}
