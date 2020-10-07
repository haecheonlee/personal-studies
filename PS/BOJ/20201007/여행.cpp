/* reference: https://jaimemin.tistory.com/686 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=3e2+1;
const int INF=1e8;

int N,M,K;
int d[MAX][MAX];
vector<pi> a[MAX];

int go(int x, int cnt) {
	if(cnt==M && x!=N) return -INF;
	if(x==N) return 0;
	
	int& ret=d[x][cnt];
	if(ret!=-1) return ret;
	ret=0;
	
	for(auto& next : a[x]) {
		int y=next.first;
		int taste=next.second;
		
		ret=max(ret, go(y, cnt+1) + taste);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M>>K;
	
	for(int i=0; i<K; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		if(u<v) a[u].push_back({v,c});
	}
	
	memset(d, -1, sizeof(d));
	cout<<go(1,1);
	
	return 0;
}
