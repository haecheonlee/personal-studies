#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

bool check[2][100001];
string s[2];

int main() {
	int N,K;
	cin>>N>>K;
	
	for(int i=0; i<2; i++) cin>>s[i];
	
	queue<pi> q;
	q.push(make_pair(0,0));
	check[0][0]=true;
	int t=0;
	
	while(!q.empty()) {
		queue<pi> cq=q;
		q=queue<pi>();
		
		while(!cq.empty()) {
			int x=cq.front().first;
			int y=cq.front().second;
			cq.pop();
			
			// next(+1)
			if(t<y+1) {
				if(y+1>=N) {
					cout<<1;
					return 0;
				}
				
				if(check[x][y+1]==false && s[x][y+1]=='1') {
					check[x][y+1]=true;
					q.push(make_pair(x,y+1));
				}
			}
			
			// prev(-1)
			if(y-1>=0 && t<y-1) {
				if(check[x][y-1]==false && s[x][y-1]=='1') {
					check[x][y-1]=true;
					q.push(make_pair(x,y-1));
				}
			}
			
			// jump
			int nx=1-x;	// switch lane
			if(t<y+K) {
				if(y+K>=N) {
					cout<<1;
					return 0;
				}
				
				if(check[nx][y+K]==false && s[nx][y+K]=='1') {
					check[nx][y+K]=true;
					q.push(make_pair(nx,y+K));	
				}
			}
		}
		
		t++;
	}
	
	cout<<0;
	
	return 0;
}
