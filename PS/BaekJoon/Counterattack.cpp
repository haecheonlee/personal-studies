#include <iostream>

using namespace std;
using pi=pair<int,int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		int N,L1,L2,S1,S2;
		cin>>N>>L1>>L2>>S1>>S2;
		
		pi a[N+1][2];	// player 1
		pi d[N+1][2];
		
		a[0][0].first=a[0][0].second=L1;
		a[0][1].first=a[0][1].second=L2;
		
		for(int i=1; i<=N-1; i++) cin>>a[i][0].first;
		for(int i=1; i<=N-1; i++) cin>>a[i][0].second;
		for(int i=1; i<=N-1; i++) cin>>a[i][1].first;
		for(int i=1; i<=N-1; i++) cin>>a[i][1].second;
		
		a[N][0].first=a[N][0].second=S1;
		a[N][1].first=a[N][1].second=S2;

		d[1][0].first=L1+a[1][0].first; d[1][0].second=L1+a[1][0].second;
		d[1][1].first=L2+a[1][1].first; d[1][1].second=L2+a[1][1].second;
		for(int i=2; i<=N; i++) {
			d[i][0].first=min(d[i-1][0].second, d[i-1][1].first)+a[i][0].first;
			d[i][0].second=min(d[i-1][0].second, d[i-1][1].first)+a[i][0].second;
			d[i][1].first=min(d[i-1][0].first, d[i-1][1].second)+a[i][1].first;
			d[i][1].second=min(d[i-1][0].first, d[i-1][1].second)+a[i][1].second;
		}
		cout<<min(min(d[N][0].first, d[N][0].second), min(d[N][1].first, d[N][1].second))<<'\n';
	}
	return 0;
}
