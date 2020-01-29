#include <iostream>
#include <queue>

using namespace std;

const int MAX=200000;
int dist[MAX];
bool checked[MAX];
int n,k;

void bfs(int idx) {
	dist[idx]=0;
	checked[idx]=true;
	queue<int> q;
	q.push(idx);
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		if(now-1>=0) {
			if(checked[now-1]==false) {
				q.push(now-1);
				checked[now-1]=true;
				dist[now-1]=dist[now]+1;
			}
		}
		
		if(now+1<MAX) {
			if(checked[now+1]==false) {
				q.push(now+1);
				checked[now+1]=true;
				dist[now+1]=dist[now]+1;
			}
		}
		
		if(now*2<MAX) {
			if(checked[now*2]==false) {
				q.push(now*2);
				checked[now*2]=true;
				dist[now*2]=dist[now]+1;
			}
		}
	}
}

int main() {
	cin>>n>>k;
	bfs(n);
	cout<<dist[k];
	
	return 0;
}

/*
boj.kr/1697

INPUT:
5 17

OUTPUT:
4
*/
