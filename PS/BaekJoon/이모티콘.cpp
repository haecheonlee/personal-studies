#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int d[1001][1001];

int main() {
	int n;
	cin>>n;

	memset(d,-1,sizeof(d));

	// first - emoticons being displayed, second - saved emoticons
	queue<pi> q;
	q.push(make_pair(1,0));
	
	d[1][0]=0;
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();

		// 1 - copy emoticon and save
		if(d[x][x]==-1 || d[x][x]>d[x][y]+1) {
			d[x][x]=d[x][y]+1;
			q.push(make_pair(x,x));
		}
		
		// 2 - paste saved emoticon
		if(x+y<=1000) {
			if(d[x+y][y]==-1 || d[x+y][y]>d[x][y]+1) {
				d[x+y][y]=d[x][y]+1;
				q.push(make_pair(x+y,y));
			}
		}
		
		// 3 - delete one
		if(x-1>=0) {
			if(d[x-1][y]==-1 || d[x-1][y]>d[x][y]+1) {
				d[x-1][y]=d[x][y]+1;
				q.push(make_pair(x-1,y));
			}
		}
	}
	
	int ans=1e9;
	for(int i=0; i<=1000; i++) {
		if(d[n][i]==-1) continue;
		ans=min(ans,d[n][i]);
	}
	cout<<ans;
	
	return 0;
}
