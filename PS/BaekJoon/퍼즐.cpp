#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int n=3;
	int start=0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int temp;
			cin>>temp;
			
			if(temp==0) temp=9;
			start=start*10+temp;
		}
	}
	
	queue<int> q;
	map<int,int> dist;
	dist[start]=0;
	
	q.push(start);
	while(!q.empty()) {
		int now_num=q.front();
		
		string now=to_string(now_num);
		q.pop();
		
		int z=now.find('9');
		int x=z/3;
		int y=z%3;
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				string next=now;
				swap(next[x*3+y], next[nx*3+ny]);
				
				int num=stoi(next);
				if(dist.count(num)==0) {
					dist[num]=dist[now_num]+1;
					q.push(num);
				}
			}
		}
	}
	
	if(dist.count(123456789)==0) cout<<-1;
	else cout<<dist[123456789];

	return 0;
}
