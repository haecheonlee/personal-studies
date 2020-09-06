#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e2+1;
const int INF=1e9;

int d[MAX][MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	vector<int> travel(M);
	for(int i=0; i<M; i++) cin>>travel[i];

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin>>d[i][j];
			if(i==j) d[i][j]=INF;
		}
	}
	
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(d[i][j]==INF) continue;
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<travel.size()-1; i++) {
		ans+=d[travel[i]][travel[i+1]];
	}
	cout<<ans;

	return 0;
}
