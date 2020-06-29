#include <iostream>
#include <algorithm>

using namespace std;

int a[1001][1001];
int d[1001][1001];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) scanf("%1d", &a[i][j]);
	}
	
	int ans=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(a[i][j]==0) continue;
			
			d[i][j]=min({d[i-1][j], d[i][j-1], d[i-1][j-1]})+1;
			ans=max(ans,d[i][j]);
		}
	}
	cout<<ans*ans;
	
	return 0;
}
