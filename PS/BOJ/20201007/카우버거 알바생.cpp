#include <iostream>
#include <vector>

using namespace std;
using pi=pair<int,int>;

const int MAX=3e2+1;

int d[MAX][MAX];

int main() {
	int N, M, K;
	cin>>N>>M>>K;
	
	vector<pi> a(N);
	for(int i=0; i<N; i++) cin>>a[i].first>>a[i].second;

	for(int i=0; i<N; i++) {
		int x=a[i].first, y=a[i].second;
		for(int j=M; j>=0; j--) {
			for(int k=K; k>=0; k--) {
				if(j-x>=0 && k-y>=0) d[j][k]=max(d[j][k], d[j-x][k-y]+1);
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<=M; i++) {
		for(int j=0; j<=K; j++) ans=max(ans, d[i][j]);
	}
	cout<<ans;

	return 0;
}
