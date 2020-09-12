#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int MAX=1501;

int N;
string s;
int d[MAX][MAX];

bool is_possible(char now, char next) {
	if(now=='B' && next=='L') return true;
	else if(now=='L' && next=='D') return true;
	else if(now=='D' && next=='B') return true;
	
	return false;
}

int main() {
	cin>>N;
	N*=3;
	
	cin>>s;
	
	queue<pair<pi,char>> q;
	if(s[0]=='B') {
		d[1][0]=1;
		q.push({{1,0}, 'B'});
	}
	
	if(s[N-1]=='B') {
		d[0][1]=1;
		q.push({{0,1}, 'B'});
	}
	
	while(!q.empty()) {
		int front=q.front().first.first;
		int back=q.front().first.second;
		char now=q.front().second;
		q.pop();
		
		if(front+back<N) {
			if(is_possible(now, s[front])) {
				if(d[front+1][back]==0) {
					d[front+1][back]=d[front][back]+1;
					q.push({{front+1, back}, s[front]});
				}
			}
			
			if(is_possible(now, s[N-1-back])) {
				if(d[front][back+1]==0) {
					d[front][back+1]=d[front][back]+1;
					q.push({{front, back+1}, s[N-1-back]});
				}
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) ans=max(ans, d[i][j]);
	}
	cout<<ans;
	
	return 0;
}
