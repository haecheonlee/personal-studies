#include <iostream>
#include <algorithm>

using namespace std;

struct City {
	int type,x,y;
};

City a[1000];
int d[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fill(d,d+1000,1e9);
	
	int N,T;
	cin>>N>>T;
	
	for(int i=0; i<N; i++) cin>>a[i].type>>a[i].x>>a[i].y;
	
	for(int i=0; i<N; i++) {
		if(a[i].type) {
			d[i]=0;
			continue;
		}
		
		for(int j=0; j<N; j++) {
			if(!a[j].type) continue;
			d[i]=min(d[i], abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
		}
	}
	
	int M;
	cin>>M;
	
	while(M--) {
		int from,to;
		cin>>from>>to;
		
		from--; to--;
		int ans=abs(a[from].x-a[to].x)+abs(a[from].y-a[to].y);
		ans=min(ans, d[from]+d[to]+T);
		if(a[from].type && a[to].type) ans=min(ans,T);
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
