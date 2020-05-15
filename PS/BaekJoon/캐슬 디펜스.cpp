#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <set>

using namespace std;

bool check[16][16];
int a[16][16];
int p[3];
int n,m,d;
vector<pair<int,int>> pos;	// position of monsters

int solve() {
	int cnt=0;
	memset(check,false,sizeof(check));
	set<pair<int,int>> l;

	for(int i=n-1; i>=0; i--) {
		for(int k=0; k<3; k++) {
			int min_distance=11;
			int x=0,y=0;
			
			bool found=false;
			for(auto &each : pos) {
				// pos of monster
				int mx,my;
				tie(mx,my)=each;
				
				// pos of archer
				int kx=i+1;
				int ky=p[k];

				int distance=abs(kx-mx)+abs(ky-my);
	
				// check validation
				if(mx>i || check[mx][my] || distance>d) continue;
				if(distance<min_distance) {
					min_distance=distance;
					x=mx;
					y=my;
					found=true;
				} else if(distance==min_distance) {
					if(my<y) {
						x=mx;
						y=my;
					}
				}
			}
			
			if(found) l.insert(make_pair(x,y));
		}
		
		// killing monster here
		cnt+=l.size();
		for(auto it : l) {
			int px,py;
			tie(px,py)=it;
			check[px][py]=true;
		}
		l.clear();
	}
	
	return cnt;
}

int main() {
	cin>>n>>m>>d;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
			if(a[i][j]==1) pos.push_back(make_pair(i,j));
		}
	}

	int mx=0;
	for(int i=0; i<m; i++) {
		for(int j=i+1; j<m; j++) {
			for(int k=j+1; k<m; k++) {
				// set the position of each archer
				p[0]=i, p[1]=j, p[2]=k;
				int temp=solve();
				mx=max(mx,temp);
			}
		}
	}
	cout<<mx;
	
	return 0;
}
