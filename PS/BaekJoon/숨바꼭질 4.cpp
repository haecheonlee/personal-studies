#include <iostream>
#include <queue>

using namespace std;

const int MAX=200000;

int dist[MAX];
int track[MAX];
bool check[MAX];

void bfs(int x) {
	queue<int> q;
	q.push(x);

	dist[x]=0;
	check[x]=true;
	track[x]=0;
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		if(now-1>=0) {
			if(check[now-1]==false) {
				q.push(now-1);
				dist[now-1]=dist[now]+1;
				check[now-1]=true;
				track[now-1]=now;
			}
		}
		
		if(now+1<MAX) {
			if(check[now+1]==false) {
				q.push(now+1);
				dist[now+1]=dist[now]+1;
				check[now+1]=true;
				track[now+1]=now;
			}
		}
		
		if(now*2<MAX) {
			if(check[now*2]==false) {
				q.push(now*2);
				dist[now*2]=dist[now]+1;
				check[now*2]=true;
				track[now*2]=now;
			}
		}
	}
}

void show(int n, int m) {
	if(n != m) show(n, track[m]);
	cout<<m<<' ';
}

int main() {
	int n,k;
	cin>>n>>k;
	
	bfs(n);
	cout<<dist[k]<<'\n';
	show(n,k);

	return 0;
}

/*
boj.kr/13913

INPUT:
5 17

OUTPUT:
4
5 4 8 16 17
*/
