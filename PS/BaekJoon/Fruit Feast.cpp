#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int MAX=5e6+1;

bool d[MAX][2];

int main() {
	int N,A,B;
	cin>>N>>A>>B;
	
	queue<pi> q;
	q.push({0,0});
	d[0][0]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int water=q.front().second;
		q.pop();

		// A
		if(x+A<=N) {
			int ax=x+A;
			if(d[ax][water]==false) {
				d[ax][water]=true;
				q.push({ax, water});
			}
		}
		
		// B
		if(x+B<=N) {
			int bx=x+B;
			if(d[bx][water]==false) {
				d[bx][water]=true;
				q.push({bx, water});
			}
		}
		
		// half
		int half=x/2;
		if(water==0) {
			if(d[half][water+1]==false) {
				d[half][water+1]=true;
				q.push({half, water+1});
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<=N; i++) {
		if(d[i][0] || d[i][1]) ans=i;
	}
	cout<<ans;
	
	return 0;
}
