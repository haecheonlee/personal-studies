#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int INF=1e9;
const int MAX=2501;

int a[51][51];
int d[51][51];
vector<pi> p[MAX];

int main() {
	int N,K;
	cin>>N>>K;
	
	// setting
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin>>a[i][j];
			
			if(a[i][j]==1) d[i][j]=0;
			else d[i][j]=INF;
			
			p[a[i][j]].push_back({i,j});	
		}
	}
	
	for(int i=1; i<K; i++) {
		for(auto& v1 : p[i]) {
			int x1=v1.first;
			int y1=v1.second;
			
			for(auto& v2 : p[i+1]) {
				int x2=v2.first;
				int y2=v2.second;
				
				int distance=abs(x1-x2)+abs(y1-y2);
				if(d[x2][y2]>d[x1][y1]+distance) {
					d[x2][y2]=d[x1][y1]+distance;
				}
			}
		}
	}
	
	int ans=-1;
	for(auto& v : p[K]) {
		int x=v.first;
		int y=v.second;
		
		if(d[x][y]==INF) continue;
		if(ans==-1 || ans>d[x][y]) ans=d[x][y];
	}
	cout<<ans;
	
	return 0;
}
