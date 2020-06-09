#include <iostream>
#include <vector>

using namespace std;

int a[1025][1025];
int tree[1025][1025];
int n,m;

int sum(int x, int y) {
	int ans=0;	
	for(int i=x; i>0; i-=i&-i) {
		for(int j=y; j>0; j-=j&-j) ans+=tree[i][j];
	}
	return ans;
}

void update(int x, int y, int value) {
	for(int i=x; i<=n; i+=i&-i) {
		for(int j=y; j<=n; j+=j&-j) tree[i][j]+=value;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			update(i,j,a[i][j]);
		}
	}
	
	while(m--) {
		int w;
		cin>>w;
		
		if(w==0) {
			int x,y,val;
			cin>>x>>y>>val;
			
			update(x,y, val-a[x][y]);
			a[x][y]=val;
		} else {
			int x1, y1, x2, y2;
			cin>>x1>>y1>>x2>>y2;
			
			cout<<sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1)<<'\n';
		}
	}
	
	return 0;
}
